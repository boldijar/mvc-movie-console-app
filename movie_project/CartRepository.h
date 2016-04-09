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

	/* */
};

