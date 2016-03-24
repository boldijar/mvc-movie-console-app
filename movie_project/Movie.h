#pragma once

#include <string>
using namespace std;

class Movie
{
private:
	int id;
	string title;
	string genre;
	string actor;
	int year;

public:
	Movie(string,string,string,int);
};

