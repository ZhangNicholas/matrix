#include <iostream>

// #include "includes/matrix.h"
#include "matrix.h"

/*! \mainpage Matrix
 *
 * Otus C++ Developer course
 * 
 * Homework #5
 * 
 * Task: design endless 2-d matrix filled with default values.
 * Matrix must support [][] subscript operator, size() method and iterator.
 */

int main()
{
	const int default_value = 0;
	const size_t matrix_size = 10;
	using MatrixType = int;
	PseudoMatrix<MatrixType, default_value> matrix;

	for (size_t i = 0; i < matrix_size; ++i)
	{
		for (size_t j = 0; j < matrix_size; ++j)
		{
			if (i == j)
				matrix[i][j] = static_cast<MatrixType>(i);
			if (i + j == matrix_size - 1)
				matrix[i][j] = static_cast<MatrixType>(j);
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