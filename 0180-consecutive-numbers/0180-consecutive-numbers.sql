# Write your MySQL query statement below
with getnum as (
    select num,id,lag(num,1) over(order by id) as prev1,lag(num,2) over(order by id) as prev2, lead(num,1) over(order by id) as next1
    from Logs
)

select distinct num as ConsecutiveNums
from getnum
where (num=prev1 and num=prev2) or (num=prev1 and num=next1);