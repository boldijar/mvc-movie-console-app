#pragma once
#include "Repository.h"
#include "Movie.h"
class Controller
{

public:
	Repository repository;
	Controller();

	Movie findMovieByTitle(string title);
	DynamicVector<Movie> findMoviesOfYear(int year);
	DynamicVector<Movie> findMoviesOfTitle(string);
	DynamicVector<Movie> getSortedMoviesByYear();
	DynamicVector<Movie> getSortedMoviesByActor();
	DynamicVector<Movie> getSortedMoviesByYearAndGenre();
};

