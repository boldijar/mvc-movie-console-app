#pragma once
#include "MoviesRepository.h"
#include "Movie.h"
#include "CartRepository.h"
class Controller
{

public:
	MoviesRepository repository;
	CartRepository cartRepository;
	Controller();
	Controller(MoviesRepository);

	Movie findMovieByTitle(string title);
	DynamicVector<Movie> findMoviesOfYear(int year);
	DynamicVector<Movie> findMoviesOfTitle(string);
	DynamicVector<Movie> getSortedMoviesByTitle();
	DynamicVector<Movie> getSortedMoviesByYear();
	DynamicVector<Movie> getSortedMoviesByActor();
	DynamicVector<Movie> getSortedMoviesByYearAndGenre();
	DynamicVector<Movie> getRandomMovies(int howMany);
	void generateRandomCart(int howManyMovies);
	void outputCartsToFile(char* filename);
	
};

