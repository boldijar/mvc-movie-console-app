#pragma once
#include "Movie.h"
#include <vector>
class DynamicVector
{
private:
	vector<Movie> list;
public:
	DynamicVector();
	/* returns the size of the list */
	int size();

	/* ads new item */
	void add(Movie movie);

	/* removes item at position*/
	void removeAt(int position);

	// now calling DynamicVector[i] will work
	Movie &operator[](int i)
	{
		return list[i];
	}
};

