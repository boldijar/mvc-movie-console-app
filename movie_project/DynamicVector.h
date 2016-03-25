#pragma once
#include "Movie.h"
#include <vector>
class DynamicVector
{
private:
	vector<Movie> list;
public:
	DynamicVector()
	{

	}
	/* returns the size of the list */
	int size()
	{
		return this->list.size();
	}

	/* ads new item */
	void add(Movie movie)
	{
		this->list.push_back(movie);
	}

	/* removes item at position*/
	void removeAt(int position)
	{
		this->list.erase(list.begin() + position);
	}
	/* clones a vector */
	DynamicVector clone()
	{
		DynamicVector newVector;
		for (size_t i = 0; i < this->list.size(); i++)
		{
			newVector.add(this->list[i]);
		}
		return newVector;
	}

	// now calling DynamicVector[i] will work
	Movie &operator[](int i)
	{
		return list[i];
	}
};
 
