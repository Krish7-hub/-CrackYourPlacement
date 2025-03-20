# Write your MySQL query statement below
-- update Salary
-- set sex = if(sex = 'm', 'f', 'm');

UPDATE Salary
set sex = case when sex = 'm' then 'f' else 'm' end;