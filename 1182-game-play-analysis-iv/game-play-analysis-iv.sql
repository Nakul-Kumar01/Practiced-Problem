-- Write your PostgreSQL query statement below

select round((count(distinct player_id)::numeric/(select count( distinct player_id) from activity)),2) fraction
from Activity 
where (player_id, event_date) IN (
    SELECT
        player_id,
        MIN(event_date) + INTERVAL '1 day'
    FROM Activity
    GROUP BY player_id
);