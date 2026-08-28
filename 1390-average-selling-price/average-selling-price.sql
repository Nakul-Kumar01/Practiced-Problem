-- Write your PostgreSQL query statement below

select product_id, coalesce(round(sum(pri):: numeric/sum(units),2),0) average_price 
from (
    select p.product_id,u.units, (p.price * u.units) pri
from Prices p
left join 
UnitsSold u 
on p.product_id = u.product_id  and p.start_date <= u.purchase_date and u.purchase_date <= p.end_date
) group by product_id;