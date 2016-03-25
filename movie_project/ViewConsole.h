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
	void showMovies();

	/* reads a movie from keyboard*/
	Movie readMovie();

	/* adds a movie to repository, if is valid, shows error otherwise */
	void addMovie(Movie movie);

	/* changes a movie by id */

	void changeMovie();

public:
	ViewConsole();
	/* starts the app */
	void start();
	

};

