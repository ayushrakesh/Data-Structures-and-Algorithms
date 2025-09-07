# Write your MySQL query statement below
select a.name, sum(case when b.distance is not null then b.distance else 0 end) as travelled_distance
from Users a left join Rides b
on a.id=b.user_id
group by a.id
order by travelled_distance desc, a.name asc