SELECT title from ratings
JOIN movies ON movie_id = id
WHERE rating = 10.0;
