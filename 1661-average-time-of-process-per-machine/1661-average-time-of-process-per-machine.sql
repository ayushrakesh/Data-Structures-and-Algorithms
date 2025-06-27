# Write your MySQL query statement below
select A.machine_id, round(avg(A.timestamp - B.timestamp),3) as processing_time
from Activity as A join Activity as B  on (A.machine_id = B.machine_id and A.process_id = B.process_id and A.activity_type = 'end' and B.activity_type = 'start')
group by A.machine_id;