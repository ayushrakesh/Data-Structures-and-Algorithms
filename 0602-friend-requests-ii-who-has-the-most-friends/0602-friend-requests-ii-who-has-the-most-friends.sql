# Write your MySQL query statement below
with getvalidacceptor as (
    select * from RequestAccepted where accepter_id is not null
)
,

getfullfriends as(
    select accepter_id as id,count(requester_id) as num
    from getvalidacceptor
    group by accepter_id

union all

    select requester_id , count(accepter_id)
    from getvalidacceptor
    group by requester_id
)

select id,sum(num) as num 
from getfullfriends
group by id
order by num desc
limit 1;
