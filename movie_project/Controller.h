#pragma once
#include "Repository.h"

class Controller
{

public:
	Repository repository;
	Controller();

	Movie findMovieByTitle(string title);
	DynamicVector findMoviesOfYear(int year);
	DynamicVector findMoviesOfTitle(string);
	DynamicVector getSortedMoviesByYear();
};

