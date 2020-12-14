#include <gtest/gtest.h>
#include "matrix.h"

TEST(size, emptyMatrixHasZeroSize) {
	const int default_value = 0;
	PseudoMatrix<int, default_value> matrix;
	matrix[0][0] = 0;
	ASSERT_EQ(matrix.size(), 0);
}

TEST(size, nonEmptyMatrixHasValidSize) {
	const int default_value = 0;
	PseudoMatrix<int, default_value> matrix;
	matrix[0][0] = 1;
	ASSERT_EQ(matrix.size(), 1);
}

TEST(value, emptyCellReturnsDefaultValue) {
	const int default_value = 0;
	PseudoMatrix<int, default_value> matrix;
	matrix[0][0] = 0;
	ASSERT_EQ(matrix[0][0], default_value);
}

TEST(value, CellReturnsCorrectValue) {
	const int default_value = 0;
	const int value = 42;
	PseudoMatrix<int, default_value> matrix;
	matrix[0][0] = value;
	ASSERT_EQ(matrix[0][0], value);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}