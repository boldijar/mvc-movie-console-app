// movie_project.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include "TestApp.h"
#include "ViewConsole.h"
using namespace std;

int main()
{
	TestApp test;
	test.runAll();
	ViewConsole viewConsole;
	viewConsole.start();
	system("PAUSE");
    return 0;
}

