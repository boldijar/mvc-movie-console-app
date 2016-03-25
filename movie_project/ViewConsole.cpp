#include "ViewConsole.h"
#include <iostream>
using namespace std;

void ViewConsole::showMovies()
{
	for (int i = 0; i < controller.repository.movies.size(); i++)
	{
		showMovie(controller.repository.movies[i]);
	}
}

ViewConsole::ViewConsole()
{
}

void ViewConsole::start()
{
	while (1)
	{
		showOptions();
		int option = getOption();
		handleOption(option);
	}
}

void ViewConsole::showOptions()
{
	printf("1) List all movies\n");
	printf("2) Add movie\n");
	printf("3) Change movie\n");
	printf("4) Remove movie\n");
}

int ViewConsole::getOption()
{
	int option;
	cin >> option;
	return option;
}

void ViewConsole::handleOption(int option)
{
	switch (option)
	{
	case 1:
		showMovies();
		break;
	default:
		cout << "Invalid option." << endl;
		break;
	}
}

void ViewConsole::showMovie(Movie movie)
{
	cout << movie.getId() << ") " << "Title: " << movie.title << " Actor: " << movie.actor << " Genre: " << movie.genre << " Year: " << movie.year << endl;
}
