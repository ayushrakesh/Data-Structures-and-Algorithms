# Write your MySQL query statement below

select id, coalesce(case when id%2=1 then lead(student,1) over(order by id) else lag(student,1) over(order by id) end, student) as student
from Seat;