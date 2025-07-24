# Write your MySQL query statement below


select  t.name as results
from (
    select u.user_id, u.name, count(movie_id) as movies
from Users u left join MovieRating m
    on u.user_id = m.user_id
    group by u.user_id
    order by movies desc, u.name asc
    limit 1
)t

union all

select t.title
from(
    select m.movie_id, m.title, avg(mr.rating) as avg_rating
    from Movies m left join MovieRating mr
    on m.movie_id = mr.movie_id and mr.created_at between '2020-02-01' and '2020-02-29'
    group by m.movie_id
    order by avg_rating desc, m.title asc
    limit 1
)t;


