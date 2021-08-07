SELECT DISTINCT people.name FROM ratings
JOIN movies ON  ratings.movie_id = movies.id
JOIN directors ON directors.movie_id =movies.id
JOIN people ON  people.id = directors.person_id
WHERE rating > 8.9 ;