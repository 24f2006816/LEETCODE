with RankedEmployee as (
    select e.name as Employee,
    e.salary as salary,
    e.departmentid,
    DENSE_RANK() OVER (
        PARTITION BY e.departmentId order by e.salary desc
    ) as rnk
    from employee e
)
select d.name as department, r.employee, r.salary
from RankedEmployee r
join Department d
on r.departmentId = d.id
where r.rnk <= 3