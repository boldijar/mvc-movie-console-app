// movie_project.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include "MoviesFileRepository.h"
#include <algorithm>
#include "TestApp.h"
#include "ViewConsole.h"
using namespace std;

int main()
{
	TestApp test;
	//test.runAll();
	MoviesFileRepository repo = MoviesFileRepository();
	Controller controller = Controller(repo);
	ViewConsole viewConsole(controller);
	viewConsole.start();
	system("PAUSE");
    return 0;
}

