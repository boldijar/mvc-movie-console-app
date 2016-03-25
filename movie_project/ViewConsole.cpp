#include "ViewConsole.h"
#include <iostream>
using namespace std;

void ViewConsole::showMovies(DynamicVector<Movie> movies)
{
	for (int i = 0; i < movies.size(); i++)
	{
		showMovie(movies[i]);
	}
}

Movie ViewConsole::readMovie()
{
	string title;
	cout << "Title: ";
	cin >> title;
	string genre;
	cout << "Genre: ";
	cin >> genre;
	string actor;
	cout << "Actor: ";
	cin >> actor;
	int year;
	cout << "Year: ";
	cin >> year;
	return Movie(title, genre, actor, year);
}

void ViewConsole::addMovie(Movie movie)
{
	try
	{
		controller.repository.addMovie(movie);
		cout << "Successfully added!"<<endl;
	}
	catch (std::exception)
	{
		cout << "Invalid fields for movie."<<endl;
	}
}

void ViewConsole::changeMovie()
{
	int id;
	cout << "Id of the movie you wanna change: ";
	cin >> id;
	Movie movie = readMovie();

	try
	{
		if (controller.repository.editMovie(id, movie))
		{
			cout << "Successfully changed!" << endl;
		}
		else
		{
			cout << "Invalid id" << endl;
		}
	}
	catch (exception)
	{
		cout << "The movie has some invalid fields!"<<endl;
	}
}

void ViewConsole::removeMovie()
{
	int id;
	cout << "Id of the movie you want to delete: ";
	cin >> id;
	controller.repository.removeMovie(id);
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
		if (handleOption(option))
		{
			break;
		}
	}
}

void ViewConsole::showOptions()
{
	printf("0) Exit\n");
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

bool ViewConsole::handleOption(int option)
{	
	if(option==0)
	{
		return true;
	}
	else if (option == 1) {
		showMovies(controller.repository.movies);
	}
	else if (option == 2)
	{
		Movie movie = readMovie();
		addMovie(movie);
	}
	else if (option == 3)
	{
		changeMovie();
	}
	else if (option == 4)
	{
		removeMovie();
	}
	else {
		cout << "Invalid option." << endl;
	}
	return false;
}

void ViewConsole::showMovie(Movie movie)
{
	cout << movie.getId() << ") " << "Title: " << movie.title << " Genre: " << movie.genre << " Actor: " << movie.actor << " Year: " << movie.year << endl;
}
