#pragma once
#include "Repository.h"
#include "Movie.h"
class Controller
{

public:
	MoviesRepository repository;
	Controller();

	Movie findMovieByTitle(string title);
	DynamicVector<Movie> findMoviesOfYear(int year);
	DynamicVector<Movie> findMoviesOfTitle(string);
	DynamicVector<Movie> getSortedMoviesByTitle();
	DynamicVector<Movie> getSortedMoviesByYear();
	DynamicVector<Movie> getSortedMoviesByActor();
	DynamicVector<Movie> getSortedMoviesByYearAndGenre();
};

