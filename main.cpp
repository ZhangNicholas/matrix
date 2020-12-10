#include <iostream>

#include "includes/matrix.h"

int main()
{
	const int default_value = -1;
	const size_t matrix_size = 10;
	PseudoMatrix<int, default_value> matrix;

	for (size_t i = 0; i < matrix_size; ++i)
	{
		for (size_t j = 0; j < matrix_size; ++j)
		{
			if (i == j)
				matrix[i][j] = static_cast<int>(i);
			if (i + j == matrix_size - 1)
				matrix[i][j] = static_cast<int>(j);
		}
	}

	for (size_t i = 1; i < matrix_size - 1; ++i)
	{
		for (size_t j = 1; j < matrix_size - 1; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Number of occupied cells: " << matrix.size() << std::endl;

	for (auto const& c : matrix)
	{
		size_t x;
		size_t y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;
	}
	
	std::cout << matrix[100][100] << std::endl;
	((matrix[100][100] = 314) = 0) = 217;
	std::cout << matrix[100][100] << std::endl;

	return 0;
}