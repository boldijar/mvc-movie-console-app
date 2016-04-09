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
		intDynamicVectorTest();
		repositoryTest();
		controllerTest();
	}
	void intDynamicVectorTest()
	{
		DynamicVector<int> vec;
		vec.add(1);
		vec.add(1);
		vec.add(5);
		vec.add(1);
		vec.add(1);
		assert(vec.size() == 5);
		DynamicVector<int> vec2 = vec.clone();
		vec2.removeAt(4);
		vec2.removeAt(3);
		assert(vec2[2] == 5);
		assert(vec2.size() == 3);

		DynamicVector<int> vec3;
		vec3.add(10);
		vec3 = vec3 + 5;
		assert(vec3[1] == 5);
		vec3.add(2);
		vec3.add(4);
		vec3 = vec3 - 2;
		assert(vec3.size() == 3);
	}
	void dynamicVectorTest()
	{
		DynamicVector<Movie> vector;
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
		MoviesRepository repository;
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
		controller3.repository.addMovie(Movie("zlala", "aa", "z1", 1));
		controller3.repository.addMovie(Movie("t100", "zc", "d1", 10));
		controller3.repository.addMovie(Movie("smek", "s2", "b1", 100));
		controller3.repository.addMovie(Movie("val", "dd", "b1", 5));

		assert(controller3.getSortedMoviesByYear()[3].title == "smek");
		assert(controller3.getSortedMoviesByActor()[3].title == "zlala");
		assert(controller3.getSortedMoviesByTitle()[3].title == "zlala");

		Controller controller4;
		controller4.repository.addMovie(Movie("Movie1", "genre_z1", "author", 1));
		controller4.repository.addMovie(Movie("Movie2", "genre_d1", "author2", 10));
		controller4.repository.addMovie(Movie("Movie3", "genre_b1", "author3", 10));
		controller4.repository.addMovie(Movie("Movie4", "genre_b1", "author4", 5));
		controller4.repository.addMovie(Movie("Movie5", "genre_b1", "author5", 3));

		DynamicVector<Movie> sortedVec = controller4.getSortedMoviesByYearAndGenre();

		assert(sortedVec[0].title == "Movie1");
		assert(sortedVec[1].title == "Movie5");
		assert(sortedVec[2].title == "Movie4");
		assert(sortedVec[3].title == "Movie3");
		assert(sortedVec[4].title == "Movie2");

	}
};