# Write your MySQL query statement below
with getsinglenumber as(
    select num, count(num) as times
    from MyNumbers
    group by num
)

select max(num) as num
from getsinglenumber
where times = 1;