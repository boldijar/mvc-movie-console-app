#pragma once

#include "DynamicVector.h"
#include "Movie.h"
class CartRepository
{

public:
	CartRepository();
	~CartRepository();
	DynamicVector<Movie> movies;

	/* will empty the cart */
	void empty();
	
	/* will add a new movie to cart */
	void add(Movie movie);

	/* adds all movies to cart */
	void addAll(DynamicVector<Movie> movies);
};

