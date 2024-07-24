#include "myMatrix.h"

myMatrix::myMatrix() {

	double value;

	std::ifstream config;
	config.open("Config.txt");
	if (config.is_open()) {

		std::string line;
		bool rowFound = false;
		bool colFound = false;
		bool valueFound = false;
		bool allFound = false;

		while (std::getline(config, line) && !allFound) {

			if (!rowFound && line.find("ROW SIZE = ") != std::string::npos) {
				size_t pos = line.find_first_not_of("ROW SIZE = ");
				std::string sub = line.substr(pos, line.length() - 1);
				nRows_ = std::stoi(sub);
				rowFound = true;
			}

			else if (!colFound && line.find("COLUMN SIZE = ") != std::string::npos) {
				size_t pos = line.find_first_not_of("COLUMN SIZE = ");
				std::string sub = line.substr(pos, line.length() - 1);
				nCols_ = std::stoi(sub);
				colFound = true;
			}

			else if (!valueFound && line.find("VALUE = ") != std::string::npos) {
				size_t pos = line.find_first_not_of("VALUE = ");
				std::string sub = line.substr(pos, line.length() - 1);
				value = std::stod(sub);
			}
			allFound = rowFound && colFound && valueFound;

		}
	}

	config.close();

	data_ = std::vector<std::vector<double>>(nRows_, std::vector<double>(nCols_, value));

}


myMatrix::myMatrix(size_t nRows, size_t nCols, double userData[]) : nRows_(nRows), nCols_(nCols)
{

	data_ = std::vector<std::vector<double>>(nRows_);

	for (size_t i = 0; i < nRows_; i++) {
		
		data_[i] = std::vector<double>(nCols_);

		for (size_t j = 0; j < nCols_; j++) {
			data_[i][j] = userData[i * nCols_ + j];
			//data_[i].emplace_back(userData[i * nCols_ + j]);
		}
	}

}

myMatrix myMatrix::operator+(const myMatrix& rhs) {

	if (this->nRows_ == rhs.nRows_ && this->nCols_ == rhs.nCols_) {
		myMatrix temp(this->nRows_, this->nCols_, 0.0);
		for (size_t i = 0; i < this->nRows_; i++) {
			std::transform(this->data_[i].begin(), this->data_[i].end(),
				rhs.data_[i].begin(), temp.data_[i].begin(), std::plus<double>());
		}
		return temp;
	}
	else
		return *this;

}