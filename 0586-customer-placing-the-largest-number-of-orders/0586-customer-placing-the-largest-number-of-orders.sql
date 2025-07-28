# Write your MySQL query statement below
with getorders as(
    select customer_number,count(*) as orders
    from Orders
    group by customer_number
)

select customer_number
from getorders
order by orders desc
limit 1;

