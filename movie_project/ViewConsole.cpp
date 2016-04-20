#include "ViewConsole.h"
#include <iostream>
using namespace std;

void ViewConsole::showMovies(DynamicVector<Movie> movies)
{
	if (movies.size() == 0)
	{
		cout << "No result." << endl;
		return;
	}
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

void ViewConsole::findMovie()
{
	string title;
	cout << "Title: ";
	cin >> title;
	Movie movie = controller.findMovieByTitle(title);
	if (movie == Movie::MOVIE_EMPTY)
	{
		cout << "Movie not found!" << endl;
	}
	else
	{
		showMovie(movie);
	}
}

void ViewConsole::filterMoviesByTitle()
{
	string title;
	cout << "Title: ";
	cin >> title;
	showMovies(controller.findMoviesOfTitle(title));
}

void ViewConsole::filterMoviesByYear()
{
	int year;
	cout << "Year: ";
	cin >> year;
	showMovies(controller.findMoviesOfYear(year));
}

void ViewConsole::sortMoviesByTitle()
{
	showMovies(controller.getSortedMoviesByTitle());
}

void ViewConsole::sortMoviesByActor()
{
	showMovies(controller.getSortedMoviesByActor());
}

void ViewConsole::sortMoviesByYearAndGenre()
{
	showMovies(controller.getSortedMoviesByYearAndGenre());
}

void ViewConsole::emptyCart()
{
	this->controller.cartRepository.empty();
	cout << "Cart was cleared!" << endl;
}

void ViewConsole::addMovieToCartByTitle()
{
	string title;
	cout << "Title: ";
	cin >> title;
	DynamicVector<Movie> movies = this->controller.findMoviesOfTitle(title);
	if (movies.size() == 0)
	{
		cout << "No movie found with the choosen title." << endl;
	}
	else
	{
		this->controller.cartRepository.add(movies[0]);
		cout << "Movie added to cart!" << endl;
	}

}

void ViewConsole::showCart()
{
	this->showMovies(this->controller.cartRepository.movies);
}

void ViewConsole::addRandomCarts()
{
	int howManyMovies;
	cout << "How many movies you want to add? ";
	cin >> howManyMovies;
	try
	{
		this->controller.generateRandomCart(howManyMovies);
		cout << "Successfully generated!" << endl;
	}
	catch (OutOfRangeException ex)
	{
		cout << "Invalid number of movies. Check the available list of movies" << endl;
	}
}

void ViewConsole::writeCart()
{
	controller.outputCartsToFile("cart.csv");
	cout << "Carts are now saved in cart.csv" << endl;
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

void ViewConsole::addMockData()
{
	/*
	controller.repository.addMovie(Movie("Titanic", "Drama", "Toni Black", 1996));
	controller.repository.addMovie(Movie("Titanic", "Comedie", "Arsenie Boca", 1998));
	controller.repository.addMovie(Movie("Manele", "Drama", "Toni Black", 2000));
	controller.repository.addMovie(Movie("Florin Salam Movie", "Horror", "Adi Minune", 1990));
	controller.repository.addMovie(Movie("Nicolae Guta", "Horror", "Dani Mocanu", 1996));
	*/
}

void ViewConsole::showOptions()
{
	printf("0) Exit\n");
	printf("1) List all movies\n");
	printf("2) Add movie\n");
	printf("3) Change movie\n");
	printf("4) Remove movie\n");
	printf("5) Find movie\n");
	printf("6) Filter movies by title\n");
	printf("7) Filter movies by year\n");
	printf("8) Sort movies by title\n");
	printf("9) Sort movies by actor\n");
	printf("10) Sort movies by year and genre\n");
	printf("	CART STUFF \n");
	printf("11) Show cart\n");
	printf("12) Empty cart\n");
	printf("13) Add movie to cart\n");
	printf("14) Generate random cart\n");
	printf("15) Print cart in file \n");
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
	else if (option == 5)
	{
		findMovie();
	}
	else if (option == 6)
	{
		filterMoviesByTitle();
	}
	else if (option == 7)
	{
		filterMoviesByYear();
	}
	else if (option == 8)
	{
		sortMoviesByTitle();
	}
	else if (option == 9)
	{
		sortMoviesByActor();
	}
	else if (option == 10)
	{
		sortMoviesByYearAndGenre();
	}
	else if (option == 11)
	{
		showCart();
	}
	else if (option == 12)
	{
		emptyCart();
	}
	else if (option == 13)
	{
		addMovieToCartByTitle();
	}
	else if (option == 14)
	{
		addRandomCarts();
	}
	else if (option == 15)
	{
		writeCart();
	}
	else {
		cout << "Invalid option." << endl;
	}
	return false;
}

void ViewConsole::showMovie(Movie movie)
{
	cout << movie.getId() << ") " << "Title: " << movie.title << ", Genre: " << movie.genre << ", Actor: " << movie.actor << ", Year: " << movie.year << endl;
}
