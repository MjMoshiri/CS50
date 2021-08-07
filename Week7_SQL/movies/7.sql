SELECT title , rating FROM movies
JOIN ratings ON movie_id = id 
ORDER BY rating , title DESC; 