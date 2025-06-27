# Write your MySQL query statement below
select A.id from Weather as A join Weather as B on DATEDIFF(A.recordDate, B.recordDate) = 1 where A.temperature > B.temperature;