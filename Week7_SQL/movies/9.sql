SELECT DISTINCT people.name FROM movies
JOIN stars ON movie_id = movies.id
JOIN people ON  person_id=people.id
WHERE movies.year = 2004 
ORDER BY people.birth ;