# Write your MySQL query statement below
select user_id , round((select count(cc.action) from Confirmations cc where cc.action = 'confirmed' and cc.user_id = c.user_id)/count(*),2) 'confirmation_rate' from Signups s left join Confirmations c using(user_id)
group by s.user_id;