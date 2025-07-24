# Write your MySQL query statement below
with stats as (
    select product_id,new_price, row_number() over(partition by product_id order by         change_date desc) as rn
    from Products
    where change_date <= '2019-08-016'
),

allproducts as (
    select distinct product_id from Products
)

select a.product_id, coalesce(s.new_price,10) as price
from allproducts a left join stats s
on a.product_id = s.product_id and s.rn=1;