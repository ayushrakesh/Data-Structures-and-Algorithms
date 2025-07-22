# Write your MySQL query statement below
with getdata as(
    select s.user_id as user_id, count(*) as Total, sum(case when c.action='confirmed' then 1 else 0 end) as     Confirmed
    from Signups s left join Confirmations c
    on s.user_id = c.user_id
    group by s.user_id
)
select user_id, (case when Total=0 then 0.0 else round(Confirmed/Total*1.00,2) end) as confirmation_rate
from getdata;
