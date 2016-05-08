#include "MoviesHtmlRepository.h"


#include <fstream>



MoviesHtmlRepository::MoviesHtmlRepository()
{
	this->loadFromFile();
}

void MoviesHtmlRepository::addMovie(Movie movie)
{
	MoviesRepository::addMovie(movie);
	this->saveToFile();
}

bool MoviesHtmlRepository::editMovie(int id, Movie movie)
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
			this->saveToFile();
			return true;
		}
	}
	return false;
}
bool MoviesHtmlRepository::movieIsValid(Movie movie)
{
	return movie.actor.size() > 0 && movie.title.size() > 0 && movie.genre.size() > 0 && movie.year > 0 && movie.year < 2017;
}

std::vector<std::string> splits(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}
void MoviesHtmlRepository::loadFromFile()
{
	ifstream file(DATABASE);
	this->movies.clear();
	std::string line;
	while (std::getline(file, line))
	{
		vector<string> columns = splits(line, ',');
		this->movies.add(Movie(columns[0], columns[1], columns[2], atoi(columns[3].c_str())));
	}
	file.close();
}

void MoviesHtmlRepository::saveToFile()
{
	ofstream file(DATABASE);
	file << "<ul>\n";
	for (int i = 0; i < this->movies.size(); i++)
	{
		Movie movie = this->movies[i];
		file <<"<li>"<< movie.title << "," << movie.genre << "," << movie.actor << "," << movie.year <<"</li>"<< endl;
	}
	file << "</ul>";
	file.close();
}

bool MoviesHtmlRepository::removeMovie(int id)
{
	for (int i = 0; i < this->movies.size(); i++)
	{
		if (this->movies[i].getId() == id)
		{
			this->movies.removeAt(i);
			this->saveToFile();
			return true;
		}
	}
	return false;
}
