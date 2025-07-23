# Write your MySQL query statement below
with getproducts as (
    select customer_id, count(distinct product_key) as cnt
    from Customer
    group by customer_id
)

select customer_id
from getproducts
where cnt = (select count(*) from Product);