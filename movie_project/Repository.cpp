#include "Repository.h"



Repository::Repository()
{
}

void Repository::addMovie(Movie movie)
{	
	if (!movieIsValid(movie))
	{
		throw std::exception("Movie has some invalid fields!");
	}
	this->movies.add(movie);
}

bool Repository::editMovie(int id, Movie movie)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		if (this->movies[i].getId() == id)
		{
			this->movies[i] = movie;
			return true;
		}
	}
	return false;
}
bool Repository::movieIsValid(Movie movie)
{
	return movie.actor.size() > 0 && movie.title.size() > 0 && movie.genre.size() > 0 && movie.year > 0 && movie.year < 2017;
}
bool Repository::removeMovie(int id)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		if (this->movies[i].getId() == id)
		{
			this->movies.removeAt(i);
			return true;
		}
	}
	return false;
}