select *
from (select id,
             name,
             COALESCE(solved_at_least_one_contest_count, 0) as solved_at_least_one_contest_count,
             COALESCE(first.take_part_contest_count, 0)     as take_part_contest_count
      from users
               full outer join (select user_id, count(*) as take_part_contest_count
                                from (select distinct on (user_id, problem_id) user_id, problem_id
                                      from submissions
                                      group by user_id, problem_id) as some_table
                                group by user_id) as first on user_id = users.id
               full outer join (select user_id, count(*) as solved_at_least_one_contest_count
                                from (select distinct on (user_id, problem_id) user_id, problem_id
                                      from submissions
                                      where success is true
                                      group by user_id, problem_id) as some_table
                                group by user_id)
          as second on id = second.user_id) as example
order by solved_at_least_one_contest_count desc, take_part_contest_count desc, id;