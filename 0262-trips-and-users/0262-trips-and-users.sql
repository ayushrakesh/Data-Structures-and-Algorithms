# Write your MySQL query statement below
with getunbanned as (
    select users_id
    from Users
    where banned = 'No'
),
getthreedaysdata as (
    select *
    from Trips
    where request_at between '2013-10-01' and '2013-10-03'
),
getcorrectdata as (
    select *
    from getthreedaysdata
    where client_id in (select * from getunbanned) and driver_id in (select * from getunbanned)
)

select request_at as Day, round(count(case when status='cancelled_by_client' then 1 when status ='cancelled_by_driver' then 1 end)/count(*),2) as 'Cancellation Rate'
from getcorrectdata
group by request_at