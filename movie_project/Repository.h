#pragma once
#pragma once
#include "DynamicVector.h"
class Repository
{
public:
	DynamicVector movies;
	Repository();

	/*adds a new movie*/
	void addMovie(Movie movie);

	/*removes a movie with the choosen id, returns true if success, otherwise false*/
	bool removeMovie(int id);

	/* changes a movie, with the choosen id, returns true if success */
	bool editMovie(int id, Movie movie);
};

