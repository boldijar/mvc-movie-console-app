#pragma once
#include "Controller.h"
class ViewConsole
{
private:
	Controller controller;
	/* show available console options */
	void showOptions();

	/* asks for input to choose options */
	int getOption();

	/* handles the choosen option, returns true if should exit */
	bool handleOption(int option);

	/* shows a movie */
	void showMovie(Movie movie);

	/* shows all movies */
	void showMovies(DynamicVector<Movie>);

	/* reads a movie from keyboard*/
	Movie readMovie();

	/* adds a movie to repository, if is valid, shows error otherwise */
	void addMovie(Movie movie);

	/* change a movie by id */
	void changeMovie();

	/* remove movie at an id */
	void removeMovie();

	/* finds a movie*/
	void findMovie();

	/* filter all the movies by title */
	void filterMoviesByTitle();

	/* filter all movies by year*/
	void filterMoviesByYear();

	/* sort movies by title */
	void sortMoviesByTitle();

	/* sort movies by actor */
	void sortMoviesByActor();

	/* sort movies by year and genre */
	void sortMoviesByYearAndGenre();

public:
	ViewConsole();
	/* starts the app */
	void start();
	/* ads some stuff into the repository as default items */
	void addMockData();
	

};

