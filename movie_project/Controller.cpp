#include "Controller.h"
#include <string>


Controller::Controller()
{
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

DynamicVector Controller::findMoviesOfYear(int year)
{
	DynamicVector list;
	for (int i = 0; i < this->repository.movies.size(); i++)
	{
		if (this->repository.movies[i].year == year)
		{
			list.add(this->repository.movies[i]);
		}
	}
	return list;
}

DynamicVector Controller::findMoviesOfTitle(string title)
{
	DynamicVector list;
	for (int i = 0; i < this->repository.movies.size(); i++)
	{
		if (this->repository.movies[i].title == title)
		{
			list.add(this->repository.movies[i]);
		}
	}
	return list;
}

DynamicVector Controller::getSortedMoviesByYear()
{
	DynamicVector clone = this->repository.movies.clone();
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

DynamicVector Controller::getSortedMoviesByActor()
{
	DynamicVector clone = this->repository.movies.clone();
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

DynamicVector Controller::getSortedMoviesByYearAndGenre()
{
	DynamicVector clone = this->repository.movies.clone();
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

