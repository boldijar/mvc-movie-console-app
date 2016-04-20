#include "Controller.h"
#include <string>
#include "OutOfRangeException.h"
#include <algorithm>
#include <random> 
#include <chrono> 
#include <fstream>

Controller::Controller()
{
}

Controller::Controller(MoviesRepository repo)
{
	this->repository = repo;
}

Movie Controller::findMovieByTitle(string title)
{
	for (int i = 0; i < this->repository.movies.size(); i++)
	{
		if (this->repository.movies[i].title == title)
		{
			return this->repository.movies[i];
		}
	}
	return Movie::MOVIE_EMPTY;
}

DynamicVector<Movie> Controller::findMoviesOfYear(int year)
{
	DynamicVector<Movie> list;
	for (int i = 0; i < this->repository.movies.size(); i++)
	{
		if (this->repository.movies[i].year == year)
		{
			list.add(this->repository.movies[i]);
		}
	}
	return list;
}

DynamicVector<Movie> Controller::findMoviesOfTitle(string title)
{
	DynamicVector<Movie> list;
	for (int i = 0; i < this->repository.movies.size(); i++)
	{
		if (this->repository.movies[i].title == title)
		{
			list.add(this->repository.movies[i]);
		}
	}
	return list;
}

DynamicVector<Movie> Controller::getSortedMoviesByTitle()
{
	DynamicVector<Movie> clone = this->repository.movies.clone();
	for (int i = 0; i < clone.size() - 1; i++)
	{
		for (int j = i + 1; j < clone.size(); j++)
		{
			if (clone[i].title.compare(clone[j].title)>0)
			{
				Movie aux = clone[i];
				clone[i] = clone[j];
				clone[j] = aux;
			}
		}
	}
	return clone;
}

DynamicVector<Movie> Controller::getSortedMoviesByYear()
{
	DynamicVector<Movie> clone = this->repository.movies.clone();
	for (int i = 0; i < clone.size() - 1; i++)
	{
		for (int j = i + 1; j < clone.size(); j++)
		{
			if (clone[i].year > clone[j].year)
			{
				Movie aux = clone[i];
				clone[i] = clone[j];
				clone[j] = aux;
			}
		}
	}
		return clone;
}

DynamicVector<Movie> Controller::getSortedMoviesByActor()
{
	DynamicVector<Movie> clone = this->repository.movies.clone();
	for (int i = 0; i < clone.size() - 1; i++)
	{
		for (int j = i + 1; j < clone.size(); j++)
		{
			if (clone[i].actor.compare(clone[j].actor)>0)
			{
				Movie aux = clone[i];
				clone[i] = clone[j];
				clone[j] = aux;
			}
		}
	}
	return clone;
}

DynamicVector<Movie> Controller::getSortedMoviesByYearAndGenre()
{
	DynamicVector<Movie> clone = this->repository.movies.clone();
	for (int i = 0; i < clone.size() - 1; i++)
	{
		for (int j = i + 1; j < clone.size(); j++)
		{
			if (clone[i].year > clone[j].year)
			{
				Movie aux = clone[i];
				clone[i] = clone[j];
				clone[j] = aux;
			}
			else if (clone[i].year == clone[j].year && clone[i].genre.compare(clone[j].genre)> 0)
			{
				Movie aux = clone[i];
				clone[i] = clone[j];
				clone[j] = aux;
			}
		}
	}
	return clone;
}

/* returns a list of random movies from repo, throws OutOfRangeException */
DynamicVector<Movie> Controller::getRandomMovies(int howMany)
{
	if (howMany<0 || howMany > this->repository.movies.size())
	{
		throw OutOfRangeException("Size is " + this->repository.movies.size());
	}
	DynamicVector<Movie> list;
	DynamicVector<Movie> shuffledOriginalList = this->repository.movies.clone();
	shuffledOriginalList.shuffle();
	for (int i = 0; i < howMany; i++)
	{
		list.add(shuffledOriginalList[i]);
	}
	return list;
}

/* adds random movies to cart , throws OutOfRangeException */
void Controller::generateRandomCart(int howManyMovies)
{
	DynamicVector<Movie> randomMovies = this->getRandomMovies(howManyMovies);
	this->cartRepository.empty();
	this->cartRepository.addAll(randomMovies);
}

/* writes all movies in cart to file */
void Controller::outputCartsToFile(char * filename)
{
	ofstream out(filename);
	for (int i = 0; i < this->cartRepository.movies.size(); i++)
	{
		Movie movie = this->cartRepository.movies[i];
		out << movie.title << "," << movie.genre << "," << movie.actor << "," << movie.year << endl;
	}
	out.close();
}

