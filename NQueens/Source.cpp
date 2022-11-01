#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

int isSafe(std::vector< std::vector<int>> &vec, int x, int y); // checks if the row is safe for a queen to be placed
void printBoard(std::vector< std::vector<int>>& vec); // will print the board onto terminal
int diagonalCheck(std::vector< std::vector<int>>& vec, int x, int y); // checks diagonals of the position given as parameter

int main()
{
	int filled = 0; // columns which are filled with queen
	int n;	// size of board is n*n
	std::cout << "Enter N: ";
	std::cin >> n; // get n from user
	
	std::stack<int> Xstack;  // stack for the x-coordinates of queens
	std::stack<int> Ystack;  // stack for the y-coordinates of queens
	std::vector< std::vector<int>> board(n, std::vector<int>(n)); // vector serves as a dynamic 2d array

	// queens are represented as 1's
	// vacant spaces are represented as 0's

	int Xrem;
	int Yrem;

	// manually place first queen at position (0,0)
	filled = filled + 1;
	board[0][0] = 1;
	Xstack.push(0);
	Ystack.push(0);

	// set the start point of the algorithm since first column is filled
	int x = 1;
	int y = 0;


	printBoard(board);
	std::cout << std::endl;



	while (filled != n) // algorithm is complete when queens fill every column of the board
	{
		if ((isSafe(board, x, y)) && (diagonalCheck(board, x, y))) // will check if the row and diagonals are safe
		{

			board[y][x] = 1; // place a queen in the position and push to stack
			Xstack.push(x);
			Ystack.push(y);
			filled++;
			x++; // move on to the next column
			y = 0; // start at the top of the next column

		}
		else
		{
			y++; // if the position isn't safe move to the next row
		}
		if (y >= n) // if we have exceeded the array limits
		{
			Xrem = Xstack.top(); // store the point on top of the stack and remove the queen
			Yrem = Ystack.top();
			board[Yrem][Xrem] = 0;
			Xstack.pop(); // pop the stack since its not a valid position
			Ystack.pop();
			x = x - 1; // move back a column
			
			y = Yrem + 1; // go to the row after the removed position

			if (y == n) // if the row isnt within limits
			{
				Xrem = Xstack.top(); // then store the point to be removed and pop of the stack
				Yrem = Ystack.top();
				board[Yrem][Xrem] = 0;
				Xstack.pop();
				Ystack.pop();
				x = Xrem;
				y = Yrem + 1;
				filled--;
			}
			filled--;
			
			
		}
		// formatting for printing array in console
		std::cout << std::endl;
		for (int q = 0; q < n; q++)
		{
			std::cout << "- ";
		}
		std::cout << std::endl;
		printBoard(board);		
		std::cout << std::endl;
	}

	// Outputting final queen positions
	std::cout << "Queen Positions: " << std::endl;

	while (!Ystack.empty() && !Xstack.empty())
	{
		std::cout << "Column: " << Xstack.top() << " | " << "Row: " << Ystack.top() << std::endl;
		Ystack.pop();
		Xstack.pop();
	}
	

	return 0;
}

int isSafe(std::vector< std::vector<int>>& vec, int x, int y)
{	
	// checks row of x
	for (int c = 0; c < vec.size(); c++) // will check the row for any queens
	{
		if ((x != c) && vec[y][c] == 1)
		{
			return 0;
		}
	}
	

	return 1;
}

int diagonalCheck(std::vector< std::vector<int>>& vec, int x, int y)
{
	int slope;

	for (int i = x-1; i >= 0; i--) // will check everything left of the row which contains the point that is being tested
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if ((vec[j][i] == 1) && (j != y))
			{
				if (abs(x - i) == abs(y - j)) // tests if the slope = 1
					return 0; // if slope = 1, then 2 points lie on the same diagonal line
				
			}
		}
	}
	
	return 1;
}


void printBoard(std::vector< std::vector<int>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
}