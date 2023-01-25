SELECT movies.title AND ratings.rating FROM movies WHERE year = 2010
JOIN ratings ON movies.id = ratings.movie_id ORDER BY ratings.rating DESC AND movies.title ASC