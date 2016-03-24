#include "Movie.h"


static int ID = 0;
Movie::Movie(string title,string genre,string actor,int year)
{
	this->title = title;
	this->genre = genre;
	this->actor = actor;
	this->year = year;
	this->id = ID++;
}
int Movie::getId()
{
	return this->id;
}
Movie Movie::MOVIE_EMPTY=Movie("","","",-1);