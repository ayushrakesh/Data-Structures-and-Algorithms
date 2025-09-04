# Write your MySQL query statement below
with empdata as (
    select d.id as dept_id ,d.name as dept_name,e.id, e.name, e.salary, dense_rank() over(partition by d.id order by e.salary desc) as rnk
    from Department d join Employee e
    on d.id= e.departmentId
)

select dept_name as Department, name as Employee, salary as Salary
from empdata
where rnk<=3