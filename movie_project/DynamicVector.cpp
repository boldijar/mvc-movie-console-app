#include "DynamicVector.h"
#include <algorithm>


DynamicVector::DynamicVector()
{
}

int DynamicVector::size()
{
	return this->list.size();
}
void DynamicVector::add(Movie movie)
{
	this->list.push_back(movie);
}
void DynamicVector::removeAt(int i)
{
	this->list.erase(list.begin() + i);
}

DynamicVector DynamicVector::clone()
{
	DynamicVector newVector;
	for (size_t i = 0; i < this->list.size(); i++)
	{
		newVector.add(this->list[i]);
	}
	return newVector;
}
