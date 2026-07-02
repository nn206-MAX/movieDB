#pragma once
#include <vector>

namespace movieData
{
	class Movies //movies object definition
	{
	public:
		//This method will be used for displaying the details about a movie [1].
		const void displayDetails() const
		{
			std::cout << movieTitle << "\t" << movieReleaseYear << "\t" << movieRating << "\t" << commentsOnTheMovie << "\n";
		}

		//A constructor is required for the creation of new objects.
		Movies(std::string movieTitleInput, int movieReleaseYearInput, int movieRatingInput, std::string commentsOnTheMovieInput)
		{
			movieTitle = movieTitleInput;
			movieReleaseYear = movieReleaseYearInput;
			movieRating = movieRatingInput;
			commentsOnTheMovie = commentsOnTheMovieInput;
		}

	private:
		std::string movieTitle;
		int movieReleaseYear;
		int movieRating;
		std::string commentsOnTheMovie;
	};
}