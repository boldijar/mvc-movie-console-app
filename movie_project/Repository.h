#pragma once
#pragma once
#include "DynamicVector.h"
#include "Movie.h"
class Repository
{
public:
	DynamicVector<Movie> movies;
	Repository();

	/*adds a new movie, throws exception if invalid movie */
	void addMovie(Movie movie);

	/*removes a movie with the choosen id, returns true if success, otherwise false*/
	bool removeMovie(int id);

	/* changes a movie, with the choosen id, returns true if success */
	bool editMovie(int id, Movie movie);

	/* returns true if movie is valid */
	bool movieIsValid(Movie movie);
};

