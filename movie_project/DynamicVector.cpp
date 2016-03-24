#include "DynamicVector.h"



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
