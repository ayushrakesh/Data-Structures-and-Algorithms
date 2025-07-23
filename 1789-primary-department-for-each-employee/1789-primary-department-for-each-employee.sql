# Write your MySQL query statement below
-- ['1', '1', 'N'],
-- ['2', '1', 'Y'], 
-- ['2', '2', 'N'], 
-- ['3', '3', 'N'], 
-- ['4', '2', 'N'], 
-- ['4', '3', 'Y'], 
-- ['4', '4', 'N']

select employee_id, department_id
from Employee where primary_flag = 'Y'

union

select employee_id, department_id
from Employee
group by employee_id having count(*)=1;