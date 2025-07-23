# Write your MySQL query statement below
with getfirstdate as (
    select player_id, min(event_date) as first_date
    from Activity 
    group by player_id
)
select round(count(distinct a.player_id)/(select count(distinct player_id) from Activity),2) as fraction
from Activity a join getfirstdate g
on a.player_id = g.player_id and datediff(a.event_date,g.first_date) = 1; 