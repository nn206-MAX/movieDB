#include <iostream> //the C++ library for standard C++ functions
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include "movieData.h"
#include "movieManagement.h"

//Vectors are effectively dynamic arrays. A vector will be used for storing all of the movies in the database.
//Syntax: std::vector<dataType> vectorName
std::vector<movieData::Movies> movieSet; //this is an external variable - it is required across multiple CPP files

static void movieAddition()
{
	std::cout << "Enter movie title: ";
	std::cin.ignore();
	std::getline(std::cin, inputMovieTitle);

	std::cout << "Enter movie release year: ";
	std::cin >> inputMovieReleaseYear;

	std::cout << "On a scale of 0 to 10, what would you rate this movie? ";
	std::cin >> inputMovieRating;

	std::cout << "\033[2J\033[1;1H"; //'clears' the screen
	std::cin.ignore();
	std::cout << "Enter your comments about the movie below.\n\n";
	std::getline(std::cin, inputCommentsOnTheMovie);

	movieData::Movies newMovie(inputMovieTitle, inputMovieReleaseYear, inputMovieRating, inputCommentsOnTheMovie);

	//adds the movie to the end of the vector
	movieSet.push_back(newMovie);

	std::cout << "\033[2J\033[1;1H"; //'clears' the screen


	char optionLetter; //Options for continuing on with movie addition: yes or no?
	std::cout << "Continue? Y/N ";
	std::cin >> optionLetter;

	if (optionLetter == 'Y' || optionLetter == 'y')
	{
		movieAddition();
	}
	else if (optionLetter == 'N' || optionLetter == 'n')
	{
		for (int i = 0; i < movieSet.size(); i++)
		{
			movieSet[i].displayDetails();
		}
	}
	else
	{
		std::exit(0);
	}
}

static void optionSelection()
{
	int optionNumber;

	//All of the options which the user can select are displayed.
	std::cout << "Options:\n1. Add new movie\n2. View movies\n";
	std::cin >> optionNumber;

	//The user has selected option 1.
	if (optionNumber == 1)
	{
		movieAddition();
	}

	//The user has selected option 2.
	else if (optionNumber == 2)
	{
		if (movieSet.size() > 0)
		{
			for (int i = 0; i < movieSet.size(); i++)
			{
				movieSet[i].displayDetails();
			}
		}
		else
		{
			std::cout << "No movies present! ";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "\033[2J\033[1;1H"; //'clears' the screen
			optionSelection();
		}
	}
	//The user has not selected a valid option.
	else
	{
		std::cout << "PLEASE SELECT A VALID OPTION. ";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "\033[2J\033[1;1H"; //'clears' the screen
		optionSelection();
	}
}

int main() //the initialiser function
{
	std::cout << "MOVIE DATABASE";
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));

	std::cout << "\033[2J\033[1;1H"; //'clears' the screen

	optionSelection();
}

//BIBLIOGRAPHY
/* [1] H.Sharma. "Creating a Vector of Class Objects in C++ - GeeksForGeeks." GeeksForGeeks.Accessed: 29 June 2026.[Online.] Available:
   https://www.geeksforgeeks.org/cpp/creating-a-vector-of-class-objects-in-cpp/ */