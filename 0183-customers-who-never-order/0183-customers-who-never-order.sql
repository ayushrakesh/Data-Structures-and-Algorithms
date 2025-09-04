# Write your MySQL query statement below
select a.name  as Customers
from Customers a left join Orders o
on a.id = o.customerId
where o.id is null