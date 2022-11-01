#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>

// brute force implementation

int main()
{
	int n;
	std::cout << "Enter size of prices array: ";
	std::cin >> n;
	std::vector<int> prices(n);
	std::vector<int> span(n);

	// get user input for daily prices
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter element of index " << i << " : ";
		std::cin >> prices[i];
	}


	std::stack<int> index;

	index.push(0); // push initial index
	span[0] = 1;	// span of first element will always be one

	for (int i = 1; i < prices.size(); i++) // start from i = 1 since i = 0 is already recorded
	{
		while ((!index.empty()) && (prices[i] >= prices[index.top()]))
		{
			index.pop(); // keep popping until we find an element greater
		}

		if (index.empty())
		{
			span[i] = i + 1; // if stack is empty means the current element is greater than every element before it so span = index + 1
		}
		else
		{
			span[i] = i - index.top(); // otherwise the span is the index subtracted by the index of the closest greater element
		}
		
		index.push(i); // keep pushing

		
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Price[day " << i << "]: " << prices[i] << " , " << "Span: " << span[i] << std::endl;
	}
	return 0;
}
