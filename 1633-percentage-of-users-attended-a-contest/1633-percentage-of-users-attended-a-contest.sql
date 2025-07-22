# Write your MySQL query statement below
with totalusers as (
    select count(*)  as users from Users
)
select r.contest_id, round((count(distinct r.user_id)*100/u.users),2) as percentage
from Register r cross join totalusers u
group by r.contest_id
order by percentage desc , r.contest_id asc;
