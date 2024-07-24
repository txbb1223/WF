#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


class myMatrix {

public:

	// Default constructor (from config file)
	myMatrix();


	// Initialize with user-defined data (assume user-defined data is a 2D array)
	myMatrix(size_t nRows, size_t nCols, double userData[]);


	// Initialize with known size
	myMatrix(size_t nRows, size_t nCols, double value) : nRows_(nRows), nCols_(nCols),
		data_(std::vector<std::vector<double>>(nRows, std::vector<double>(nCols, value))) {}



	// Copy constructor
	myMatrix(const myMatrix& rhs) {

		this->nRows_ = rhs.nRows_;
		this->nCols_ = rhs.nCols_;
		this->data_.clear();
		this->data_ = rhs.data_;

	}

	//myMatrix& operator=(const myMatrix& rhs);
	//myMatrix(myMatrix&& rhs) noexcept;
	//myMatrix& operator=(myMatrix&& rhs) noexcept;
	
public:
	// Element-wise addition
	myMatrix operator+(const myMatrix& rhs);

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
