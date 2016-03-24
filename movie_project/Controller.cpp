#include "Controller.h"



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