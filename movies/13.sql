SELECT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (SELECT movies.id from movies
JOIN people ON stars.person_id = people.id
JOIN stars ON stars.movie_id = movies.id
WHERE people.name = 'Kevin Bacon' AND people.birth = 1958) AND people.name != 'Kevin Bacon';