# Write your MySQL query statement below
select m.id 'id' from Weather m , Weather o
where m.temperature > o.temperature and datediff(m.recordDate,o.recordDate) =1;