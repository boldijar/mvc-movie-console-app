#include "Repository.h"



Repository::Repository()
{
}

void Repository::addMovie(Movie movie)
{
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