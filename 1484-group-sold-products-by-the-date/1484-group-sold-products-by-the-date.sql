# Write your MySQL query statement below
with getdata as (
    select sell_date,
    count(distinct product) as num_sold,
    group_concat(distinct product order by product asc) as products
    from Activities
    group by sell_date
)

select * from getdata;