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

	/* handles the choosen option */
	void handleOption(int option);

	/* shows a movie */
	void showMovie(Movie movie);

	/* shows all movies */
	void showMovies();
public:
	ViewConsole();
	/* starts the app */
	void start();
	

};

