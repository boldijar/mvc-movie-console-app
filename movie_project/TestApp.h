#pragma once
#include "DynamicVector.h"
#include <assert.h>
#include "Repository.h"
#include "Controller.h"
class TestApp
{
public:
	void runAll()
	{
		dynamicVectorTest();
		repositoryTest();
		controllerTest();
	}
	void dynamicVectorTest()
	{
		DynamicVector vector;
		vector.add(Movie("title", "genre", "author", 1773));
		assert(vector.size() == 1);
		vector.add(Movie("title", "genre2", "author", 1773));
		assert(vector[1].genre == "genre2");
		vector.add(Movie("title", "genre3", "author", 1773));
		vector.removeAt(1);
		assert(vector.size() == 2);
		assert(vector[1].genre == "genre3");
	}
	void repositoryTest()
	{
		Repository repository;
		repository.addMovie(Movie("t1", "g1", "a1", 2000));
		repository.addMovie(Movie("t2", "g2", "a2", 2000));
		repository.addMovie(Movie("t3", "g3", "a3", 2000));
		assert(repository.movies.size() == 3);
		assert(repository.editMovie(repository.movies[1].getId(), Movie("a", "a", "a", 2001)));
		assert(!repository.editMovie(69,Movie("a","a","a",2001)));
		assert(repository.movies[1].actor == "a");
		assert(repository.removeMovie(repository.movies[1].getId()));
		assert(repository.movies.size() == 2);
		assert(repository.movies[1].title == "t3");
		assert(!repository.removeMovie(100));
	}
	void controllerTest()
	{
		Controller controller;
		controller.repository.addMovie(Movie("t1", "g1", "a1", 2000));
		controller.repository.addMovie(Movie("t2", "g2", "a2", 2000));
		controller.repository.addMovie(Movie("t3", "g3", "a3", 2000));
		controller.repository.addMovie(Movie("t4", "g4", "a4", 2000));
		controller.repository.addMovie(Movie("t5", "g5", "a5", 2000));
		assert(controller.findMovieByTitle("t1").actor == "a1");
		assert(controller.findMovieByTitle("titanic") == Movie::MOVIE_EMPTY);
		assert(controller.repository.removeMovie(controller.findMovieByTitle("t5").getId()));
		assert(controller.findMovieByTitle("t5") == Movie::MOVIE_EMPTY);

		Controller controller2;
		controller2.repository.addMovie(Movie("t1", "g1", "a1", 1));
		controller2.repository.addMovie(Movie("t2", "g2", "a2", 2));
		controller2.repository.addMovie(Movie("t3", "g3", "a3", 3));
		controller2.repository.addMovie(Movie("t5", "g4", "a4", 3));
		controller2.repository.addMovie(Movie("t5", "g5", "a5", 5));

		assert(controller2.findMoviesOfYear(3).size() == 2);
		assert(controller2.findMoviesOfYear(100).size() == 0);
		assert(controller2.findMoviesOfYear(1).size() == 1);

		assert(controller2.findMoviesOfTitle("t1").size() == 1);
		assert(controller2.findMoviesOfTitle("titanic").size() == 0);
		assert(controller2.findMoviesOfTitle("t5").size() == 2);


		Controller controller3;
		controller3.repository.addMovie(Movie("t1", "g1", "a1", 1));
		controller3.repository.addMovie(Movie("t2", "g1", "a1", 10));
		controller3.repository.addMovie(Movie("t3", "g1", "a1", 100));
		controller3.repository.addMovie(Movie("t4", "g1", "a1", 5));

		assert(controller3.getSortedMoviesByYear()[3].title == "t3");
	}
};