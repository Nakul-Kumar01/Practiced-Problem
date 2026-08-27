-- Write your PostgreSQL query statement below
select machine_id, round(avg(dif)::numeric ,3) processing_time  from
(select a.machine_id, b.timestamp - a.timestamp as dif
from Activity a
inner join
Activity b
on 
a.machine_id = b.machine_id and a.process_id = b.process_id and a.activity_type = 'start' and b.activity_type = 'end'
)
group by machine_id;
