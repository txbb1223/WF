#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


class Matrix {

public:

	// Default constructor (from config file)
	Matrix();


	// Initialize with user-defined data (assume user-defined data is a 2D array)
	Matrix(size_t nRows, size_t nCols, double userData[]);


	// Initialize with known size
	Matrix(size_t nRows, size_t nCols, double value) : nRows_(nRows), nCols_(nCols),
		data_(std::vector<std::vector<double>>(nRows, std::vector<double>(nCols, value))) {}



	// Copy constructor
	Matrix(const Matrix& rhs) {

		this->nRows_ = rhs.nRows_;
		this->nCols_ = rhs.nCols_;
		this->data_.clear();
		this->data_ = rhs.data_;

	}

	//Matrix& operator=(const Matrix& rhs);
	//Matrix(Matrix&& rhs) noexcept;
	//Matrix& operator=(Matrix&& rhs) noexcept;
	
public:
	// Element-wise addition
	Matrix operator+(const Matrix& rhs);

public:
	const std::vector<std::vector<double>>& getData() const {
		return data_;
	}

	std::vector<std::vector<double>>::iterator begin() {
		return data_.begin();
	}

	std::vector<std::vector<double>>::iterator end() {
		return data_.end();
	}

private:

	size_t nRows_ = 0;
	size_t nCols_ = 0;
	std::vector<std::vector<double>> data_;

};
