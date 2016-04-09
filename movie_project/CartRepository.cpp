#include "CartRepository.h"



CartRepository::CartRepository()
{
}


CartRepository::~CartRepository()
{
}

void CartRepository::empty()
{
	this->movies.clear();
}

void CartRepository::add(Movie movie)
{
	this->movies.add(movie);
}

void CartRepository::addAll(DynamicVector<Movie> movies)
{
	for (int i = 0; i < movies.size(); i++)
	{
		add(movies[i]);
	}
}
