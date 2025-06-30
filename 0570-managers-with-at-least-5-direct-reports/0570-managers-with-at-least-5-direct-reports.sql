# Write your MySQL query statement below
select name
from Employee
where Employee.id in ( 
    select managerId
    from Employee
    group by managerId
    having count(*)>=5
);