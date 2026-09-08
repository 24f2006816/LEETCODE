# Write your MySQL query statement bel
SELECT email as Email
from Person
Group By email
HAVING COUNT(email) > 1