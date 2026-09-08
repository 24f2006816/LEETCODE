# Write your MySQL query statement below
select e.name, b.bonus
from employee e
left join Bonus b
on e.empId = b.empId
where b.bonus < 1000
OR b.bonus is Null