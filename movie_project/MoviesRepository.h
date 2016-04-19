#pragma once
#pragma once
#include "DynamicVector.h"
#include "Movie.h"
#include <iostream>
class MoviesRepository
{
private :
	 const char* DATABASE = "database.csv";
public:
	DynamicVector<Movie> movies;
	MoviesRepository();

	/*adds a new movie, throws exception if invalid movie */
	void addMovie(Movie movie);

	/*removes a movie with the choosen id, returns true if success, otherwise false*/
	bool removeMovie(int id);

	/* changes a movie, with the choosen id, returns true if success, throws exception if movie invalid  */
	bool editMovie(int id, Movie movie);

	/* returns true if movie is valid */
	bool movieIsValid(Movie movie);

	/* loads stuff from file */
	void loadFromFile();

	/* saves to file the movies */
	void saveToFile();
};

