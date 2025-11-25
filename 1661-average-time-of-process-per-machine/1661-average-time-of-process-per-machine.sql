# Write your MySQL query statement below
select machine_id, round(
        (
            (
                select sum(timestamp)
                from Activity a
                where
                    activity_type = 'end' and a.machine_id = Activity.machine_id
            ) - (
				select sum(timestamp)
				from Activity a
				where
					activity_type = 'start' and a.machine_id = Activity.machine_id
			)
        ) / count(DISTINCT process_id), 3
    ) 'processing_time'
from Activity
group by
    machine_id;