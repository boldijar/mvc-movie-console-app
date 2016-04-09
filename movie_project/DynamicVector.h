#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <chrono> 
template <class T> class DynamicVector
{
private:
	std::vector<T> list;
public:
	DynamicVector()
	{

	}

	/* clears all elements*/
	void clear() {
		this->list.clear();
	}

	/* shuffle elements */
	void shuffle() {
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(this->list.begin(), this->list.end(), std::default_random_engine(seed));
	}
	/* returns the size of the list */
	int size()
	{
		return this->list.size();
	}

	/* ads new item */
	void add(T item)
	{
		this->list.push_back(item);
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
		for (T item : this->list)
		{
			newVector.add(item);
		}
		return newVector;
	}

	// now calling DynamicVector[i] will work
	T &operator[](int i)
	{
		return list[i];
	}

	DynamicVector operator+(const T& item)
	{
		this->add(item);
		return *this;
	}
	DynamicVector operator-(const T&item)
	{
		for (int i = 0; i < this->list.size(); i++)
		{
			if (this->list[i] == item)
			{
				this->list.erase(this->list.begin() + i);
				return *this;
			}
		}
		return *this;
	}

};
 
