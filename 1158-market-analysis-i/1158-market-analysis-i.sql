# Write your MySQL query statement below
with cte as(
    select a.user_id, a.join_date, count(case when year(b.order_date)=2019 then 1 end) as cnt
    from Users a left join Orders b
    on a.user_id = b.buyer_id
    group by a.user_id
)

select user_id as buyer_id, join_date, cnt as orders_in_2019
from cte;