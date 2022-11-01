#include <stdio.h>
#include <vector>
#include <iostream>

// brute force implementation

int main()
{
	int n;
	std::cout << "Enter size of prices array: ";
	std::cin >> n;
	std::vector<int> prices(n);

	// get user input for daily prices
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter element of index " << i << " : ";
		std::cin >> prices[i];
	}


	std::vector<int> span(prices.size()); // array which hold the span of the stock prices
	int s; // span variable

	for (int i = 0; i < prices.size(); i++)
	{
		s = 1; // initially set to one since on the same day its equal price so span = 1
		while ((s <= i) && (prices[i - s] <= prices[i])) // checks for prices preceding prices[i]
		{
			s++;
		}

		span[i] = s;
	}

	std::cout << std::endl;
	// print span array
	for (int j = 0; j < span.size(); j++)
	{
		std::cout << "Price[day " << j << "]: " << prices[j] << " , " << "Span: " << span[j] << std::endl;
	}



	return 0;
}
