with getfirstorder as (
    select *, row_number() over(partition by customer_id order by order_date) as rn
    from Delivery
)
select round(count(case when order_date = customer_pref_delivery_date then 1 end)*100/count(*),2) as  immediate_percentage
from getfirstorder
where rn =1;