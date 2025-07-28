# Write your MySQL query statement below
with getfebdata as (
    select product_id, sum(unit) as sold_units
    from Orders
    where order_date between '2020-02-01' and '2020-02-29'
    group by product_id
    having sold_units >= 100
)

select p.product_name, g.sold_units as unit
from getfebdata g join Products p
on g.product_id = p.product_id;

