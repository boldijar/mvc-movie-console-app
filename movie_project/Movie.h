#pragma once

#include <string>
using namespace std;

class Movie
{

private:
	int id;


public:
	Movie(string, string, string, int);
	int getId();
	string title;
	string genre;
	string actor;
	int year;

	int operator==(Movie object)
	{
		return object.id == this->id;
	}
	static Movie MOVIE_EMPTY;

};

