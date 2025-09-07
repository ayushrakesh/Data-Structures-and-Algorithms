# Write your MySQL query statement below
select a.employee_id
from Employees a
where not exists (
    select 1
    from Salaries b
    where a.employee_id = b.employee_id
)

union

select a.employee_id
from Salaries a
where not exists (
    select 1
    from Employees b
    where a.employee_id = b.employee_id
)

order by employee_id
