#include <iostream>
#include "Matrix.hpp"

void setUp() {
	// Additional setup work

	// Not familiar with this in the context of loading/unloading a library - have used this concept with unit testing,
	// where "setup" prepares the environment for the entire test suite (so not repeated for very single test case),
	// and "tearDown" does the clearup work after the completion of testing. 

	// No implementation
}

void tearDown() {

	// Clean up work before unloading the library

	// No implementation
}

void printMatrix(const Matrix& mat) {

	for (auto it_r = mat.getData().begin(); it_r != mat.getData().end(); ++it_r) {
		for (auto it_c = (*it_r).begin(); it_c != (*it_r).end(); it_c++) {
			std::cout << *it_c << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	std::cout << "Matrix with known size: " << std::endl;
	Matrix mat1(2, 3, 2.0);
	printMatrix(mat1);

	std::cout << "Default matrix: " << std::endl;
	Matrix mat2;
	printMatrix(mat2);

	std::cout << "Matrix from user-defined data" << std::endl;
	double arr[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	Matrix mat3(2, 3, arr);
	printMatrix(mat3);

	std::cout << "Add three matrices: " << std::endl;
	printMatrix(mat1 + mat2 + mat3);

}
