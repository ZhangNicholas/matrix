#include <iostream>

//#include "includes/matrix.h"
#include "includes/new_matrix.h"

size_t pair_func(size_t a, size_t b) {
	return ((a + b) * (a + b + 1))/2 + b;
}

Key depair_func(const size_t hash) {
	size_t w = floor((sqrt(((double)hash * 8 + 1))-1)/2);
	size_t t = (w * w + w) / 2;
	size_t y = hash - t;
	size_t x = w - y;
	Key foo(x, y);
	return foo;
}


int main()
{
	constexpr int default_value = -1;
	constexpr size_t matrix_size = 10;
	PseudoMatrix<int, default_value> matrix;

	for (int i = 0; i < matrix_size; ++i)
	{
		for (int j = 0; j < matrix_size; ++j)
		{
			if (i == j)
				matrix[i][j] = i;
			if (i + j == matrix_size - 1)
				matrix[i][j] = j;
		}
	}

	for (int i = 1; i < matrix_size - 1; ++i)
	{
		for (int j = 1; j < matrix_size - 1; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Number of occupied cells: " << matrix.size() << std::endl;

	for (auto const& c : matrix)
	{
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;
	}
	
	std::cout << matrix[100][100] << std::endl;
	((matrix[100][100] = 314) = 0) = 217;
	std::cout << matrix[100][100] << std::endl;

	return 0;
}