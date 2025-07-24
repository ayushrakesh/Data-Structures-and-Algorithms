# Write your MySQL query statement below
with assigncategory as (
    select account_id,income, case when income < 20000 then 'Low Salary' when income > 50000 then 'High Salary' else 'Average Salary' end as category
    from Accounts
),

makecategories as (
    select 'Low Salary' as category
    union
    select 'Average Salary'
    union
    select 'High Salary'
)

select m.category, count(a.account_id) as accounts_count
from makecategories m left join assigncategory a
on m.category = a.category
group by m.category;
