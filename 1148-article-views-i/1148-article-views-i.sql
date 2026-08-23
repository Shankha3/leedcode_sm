# Write your MySQL query statement below
select distinct author_id as id
from Views
WHERE author_id = viewer_id 
order by author_id ASC;