-- Write your PostgreSQL query statement below


SELECT EU.UNIQUE_ID, E.NAME
FROM Employees E
LEFT JOIN 
EmployeeUNI EU
ON E.ID = EU.ID