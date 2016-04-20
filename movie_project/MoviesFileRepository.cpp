#include "MoviesFileRepository.h"
#include "MoviesFileRepository.h"
#include <fstream>



MoviesFileRepository::MoviesFileRepository()
{
}

void MoviesFileRepository::addMovie(Movie movie)
{
	if (!movieIsValid(movie))
	{
		throw std::exception("Movie has some invalid fields!");
	}
	this->movies.add(movie);
}

bool MoviesFileRepository::editMovie(int id, Movie movie)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		if (this->movies[i].getId() == id)
		{
			if (!movieIsValid(movie))
			{
				throw exception("Invalid movie");
			}
			this->movies[i] = movie;
			return true;
		}
	}
	return false;
}
bool MoviesFileRepository::movieIsValid(Movie movie)
{
	return movie.actor.size() > 0 && movie.title.size() > 0 && movie.genre.size() > 0 && movie.year > 0 && movie.year < 2017;
}

std::vector<std::string> split(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}
void MoviesFileRepository::loadFromFile()
{
	ifstream file(DATABASE);
	this->movies.clear();
	std::string line;
	while (std::getline(file, line))
	{
		vector<string> columns = split(line, ',');
		addMovie(Movie(columns[0], columns[1], columns[2], atoi(columns[3].c_str())));
	}
	file.close();
}

void MoviesFileRepository::saveToFile()
{
	ofstream file(DATABASE);
	for (int i = 0; i < this->movies.size(); i++)
	{
		Movie movie = this->movies[i];
		file << movie.title << "," << movie.genre << "," << movie.actor << "," << movie.year << endl;
	}
	file.close();
}

bool MoviesFileRepository::removeMovie(int id)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		if (this->movies[i].getId() == id)
		{
			this->movies.removeAt(i);
			return true;
		}
	}
	return false;
}
