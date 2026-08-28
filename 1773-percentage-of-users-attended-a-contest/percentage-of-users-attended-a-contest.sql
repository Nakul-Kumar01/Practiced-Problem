-- Write your PostgreSQL query statement below
select contest_id, round(count(r.user_id)*100.0/(select count(*) from users),2) percentage 
from users u 
join Register r
on u.user_id = r.user_id
group by contest_id
order by percentage desc, contest_id asc;