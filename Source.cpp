#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>


// no recursion involved in this version
float distanceCalc(float Xpoint, float Ypoint, float Xcentroid, float Ycentroid);

int main()
{
	srand(time(NULL));
	int itr = 0;

	float x_points[] = { 2, 4, 6, 2, 4, 1, 10, 1, 3.5 };
	float y_points[] = { 1, 2, 3, 5, 2, 8, 3, 9, 11 };
	const int num_of_points = 9;

	// This program only works with 2 clusters
	const int k = 2;

	float next_centroid1[] = { 0,0 };
	float next_centroid2[] = { 0,0 };

	// need to randomly pick 2 centroids

	
	int centroid_count = k;

	float c1[] = { 0,0 }; // initialize
	int point_index_c1 = rand() % num_of_points; // Picks a point to be a centroid
	c1[0] = x_points[point_index_c1]; // X coordinate of first centroid
	c1[1] = y_points[point_index_c1]; // Y coordinate of first centroid
	
									// possible error: centroids are the same point
	
	float c2[] = { 0,0 };
	int point_index_c2 = rand() % num_of_points; // Picks a point to be a centroid
	c2[0] = x_points[point_index_c2]; // X coordinate of first centroid
	c2[1] = y_points[point_index_c2]; // Y coordinate of first centroid

	std::cout << "Initial Centroid 1 is: ";
	std::cout << c1[0] << " , ";
	std::cout << c1[1] << std::endl;

	std::cout << "Initial Centroid 2 is: ";
	std::cout << c2[0] << " , ";
	std::cout << c2[1] << std::endl;

	// matrix which stores distances to each centroid
	float distance_matrix[k][num_of_points];

	int run = 1;

	// if this error occurs program will stop running
	if ((c1[0] == c2[0]) && (c1[1] == c2[1]))
		run = 0;


	
	while (run)
	{

		for (int i = 0; i < num_of_points; i++)
		{
			float distance = distanceCalc(x_points[i], y_points[i], c1[0], c1[1]);
			distance_matrix[0][i] = distance;
		}

		for (int i = 0; i < num_of_points; i++)
		{
			float distance = distanceCalc(x_points[i], y_points[i], c2[0], c2[1]);
			distance_matrix[1][i] = distance;
		}


		float Imatrix[k][num_of_points];

		for (int p = 0; p < num_of_points; p++)
		{
			if (std::min(distance_matrix[0][p], distance_matrix[1][p]) == distance_matrix[0][p])
			{
				Imatrix[0][p] = 1;
				Imatrix[1][p] = 0;
			}
			else
			{
				Imatrix[0][p] = 0;
				Imatrix[1][p] = 1;
			}
		}

		// find average of clusters
		// first cluster
		float Xsum = 0;
		float Ysum = 0;
		int counter = 0;
		// second cluster
		float Xsum2 = 0;
		float Ysum2 = 0;
		int counter2 = 0;

		for (int i = 0; i < num_of_points; i++)
		{
			if (Imatrix[0][i] == 1)
			{
				counter++;
				Xsum = Xsum + x_points[i];
				Ysum = Ysum + y_points[i];
			}
			else
			{
				counter2++;
				Xsum2 = Xsum2 + x_points[i];
				Ysum2 = Ysum2 + y_points[i];
			}
		}

		next_centroid1[0] = Xsum / counter;
		next_centroid1[1] = Ysum / counter;

		next_centroid2[0] = Xsum2 / counter2;
		next_centroid2[1] = Ysum2 / counter2;

		if ((next_centroid1[0] == c1[0]) && (next_centroid1[1] == c1[1]) && (next_centroid2[0] == c2[0]) && (next_centroid2[1] == c2[1]))
		{
			run = 0;
		}
		else
		{
			itr++;
			c1[0] = next_centroid1[0];
			c1[1] = next_centroid1[1];
			c2[0] = next_centroid2[0];
			c2[1] = next_centroid2[1];
			std::cout << "centroid 1 (on " << itr << " iteration): " << c1[0] << " , " << c1[1] << std::endl;
			std::cout << "centroid 2 (on " << itr << " iteration): " << c2[0] << " , " << c2[1] << std::endl;
			
		}


	}
	std::cout << "Final centroid c1: " << c1[0] << " , " << c1[1] << std::endl;
	std::cout << "Final centroid c2: " << c2[0] << " , " << c2[1] << std::endl;
}

float distanceCalc(float Xpoint, float Ypoint, float Xcentroid, float Ycentroid)
{
	float distance = 0;

	distance = sqrtf(  pow(Xcentroid - Xpoint,2) + pow(Ycentroid - Ypoint, 2)	);
	
	return distance;;
}