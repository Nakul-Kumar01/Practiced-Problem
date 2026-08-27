-- Write your PostgreSQL query statement below

SELECT customer_id , COUNT(*) count_no_trans 
FROM VISITS V 
WHERE VISIT_ID NOT IN (
    SELECT VISIT_ID FROM Transactions
)
GROUP BY customer_id ;