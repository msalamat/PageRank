//
// Created by Mohammad Salamat on 2019-01-28.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>

#include "matrix.hpp"

/**
 * A helper method.
 *
 * Determines whether a number is a square number
 * @param n the number in question
 * @return true, whether or not it is square
 */
bool isSquare(int n) {
	int sq = (int) sqrt(n);
	return sq*sq == n;
}

Matrix::Matrix() {
	vector<double> babyVector;
	babyVector.push_back(0.0);
	daddyVector.push_back(babyVector);
}

Matrix::Matrix(int n) {

	if (n <= 0) {
		throw invalid_argument("n cannot be <= 0");
	}

	for (int i = 0; i < n; i++) {
		vector<double> babyVector;
		for (int j = 0; j < n; j++) {
			babyVector.push_back(0.0);
		}
		daddyVector.push_back(babyVector);
	}
}

Matrix::Matrix(int r, int c) {

	if (r <= 0 || c <= 0) {
		throw invalid_argument("one or both of the parameters was <= 0");
	}

	for (int i = 0; i < r; i++) {
		vector<double> babyVector;
		for (int j = 0; j < c; j++) {
			babyVector.push_back(0.0);
		}
		daddyVector.push_back(babyVector);
	}
}

Matrix::Matrix(double *p, int size) {
	if (!isSquare(size)) {
		throw invalid_argument("size of array is not an integer square root");
	}

	int counter = 0, sqrt_size = (int) sqrt(size);

	for (int i = 0; i < sqrt_size; i++) {
		vector<double> babyVector;

		for (int j = 0; j < sqrt_size; j++) {
			babyVector.push_back(* (p+counter));
			counter++;
		}

		daddyVector.push_back(babyVector);
	}
}

void Matrix::printMatrix() {

	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			cout << daddyVector[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::set_value(const int row, const int column, const double newNum) {
	if (row > (int) daddyVector.size() || column > (int) daddyVector[0].size() ||
	     row < 0 || column < 0) {
		throw invalid_argument("row or column (or both) was out of bounds");
	}

	daddyVector[row][column] = newNum;
}

double Matrix::get_value(int row, int column) {
	if (row > (int) daddyVector.size() || column > (int) daddyVector[0].size() ||
		row < 0 || column < 0) {
		throw invalid_argument("row or column (or both) was out of bounds");
	}

	return daddyVector[row][column];
}

void Matrix::clear() {
	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			daddyVector[i][j] = 0.0;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < (int) daddyVector.size(); i++) {
		daddyVector[i].clear();
		daddyVector[i].shrink_to_fit();
	}
	daddyVector.clear();
	daddyVector.shrink_to_fit();
}

ostream &operator<<(ostream & o, Matrix & m)  {

	for (int i = 0; i < (int) m.daddyVector.size(); i++) {
		for (int j = 0; j < (int) m.daddyVector[i].size(); j++){
			o << m.daddyVector[i][j] << "\t";
		}
		o << endl;
	}
	return o;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {

	// size of daddy, i.e. number of rows
	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		return false;
	// row size
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		return false;

	double smallerNum, biggerNum;

	for (int i = 0; i < (int) lhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) lhs.daddyVector[i].size(); j++) {
			smallerNum = min(lhs.daddyVector[i][j], rhs.daddyVector[i][j]);
			biggerNum = max(lhs.daddyVector[i][j], rhs.daddyVector[i][j]);
			if (biggerNum > smallerNum + Matrix::tolerance)
				return false;
		}
	}

	return true;
}

bool operator!=(Matrix &lhs, Matrix &rhs) {
	 //return !operator==(lhs, rhs); both work
	 return !(lhs==rhs);
}

Matrix &Matrix::operator++() {

	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			++daddyVector[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix old(*this);
	operator++();
	return old;
}

Matrix &Matrix::operator--() {
	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		for (unsigned long j = 0; j < daddyVector[i].size(); j++) {
			--daddyVector[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator--(int) {
	Matrix old(*this);
	operator--();
	return old;
}

Matrix& Matrix::operator=(Matrix rhs) {
	mySwap(*this, rhs);
	return *this;
}

void Matrix::mySwap(Matrix &matrix, Matrix rhs) {
	for (int i = 0; i < (int) rhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) rhs.daddyVector[i].size(); j++) {
			matrix.daddyVector[i][j] = rhs.daddyVector[i][j];
		}
	}
}

Matrix& Matrix::operator+=(const Matrix &rhs) {

	*this = *this + rhs;

	return *this;
}

Matrix operator+(Matrix lhs, const Matrix &rhs) {

	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		throw invalid_argument("not same size error");
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		throw invalid_argument("not same size error");

	for (int i = 0; i < (int) lhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) lhs.daddyVector[i].size(); j++) {
			lhs.daddyVector[i][j] += rhs.daddyVector[i][j];
		}
	}

	return lhs;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
	*this = *this - rhs;

	return *this;
}

Matrix operator-(Matrix lhs, const Matrix &rhs) {
	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		throw invalid_argument("not same size, error");
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		throw invalid_argument("not same size, error");

	for (unsigned long i = 0; i < lhs.daddyVector.size(); i++) {
		for (unsigned int j = 0; j < lhs.daddyVector[i].size(); j++) {
			lhs.daddyVector[i][j] -= rhs.daddyVector[i][j];
		}
	}
	return lhs;

}

Matrix &Matrix::operator*=(const Matrix &rhs) {
	*this = *this - rhs;

	return *this;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {

	if (lhs.daddyVector[0].size() != rhs.daddyVector.size()) {
		throw invalid_argument("col lhs must == row of rhs");
	}

	// an "n x m"
	int n = (int) lhs.daddyVector.size();
	int m = (int) rhs.daddyVector[0].size();
	int l = (int) rhs.daddyVector.size();

	Matrix resulting_matrix{n,m};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			double result = 0;
			for (int k = 0; k < l; k++) {
				result += lhs.daddyVector[i][k] * rhs.daddyVector[k][j];
			}
			resulting_matrix.daddyVector[i][j] = result;
		}
	}

	return resulting_matrix;
}

/**
 * Check if a matrix has any full zeros in a column
 * @param m a matrix
 * @return The first occurance of a column with all zeroes
 */
int Matrix::getColoumnIfAllZeroes(const Matrix &m) {

	int count = 0;

	for (int i = 0; i < (int) m.daddyVector[0].size(); i++) { // loop column by column
		for (int j = 0; j < (int) m.daddyVector.size(); j++) {
			if (m.daddyVector[j][i] == 0)
				break;
			else
				count++;

		}

		if (count == (int) m.daddyVector[0].size())
			return i; // the col with all zeroes

		count = 0;
	}


	return -1;
}

Matrix Matrix::getImportanceMatrix() {
	Matrix m = *this;
	int mSize = (int) m.daddyVector.size();
	for (int i = 0; i < mSize; i++) {
		double colWeight = 0;
		for (int j = 0; j < mSize; j++) {
			colWeight += m.daddyVector[j][i];

		}
		if (colWeight == 0) {
			for (int j = 0; j < mSize; j++) {
				m.daddyVector[j][i] = 1.0/mSize;
			}
		} else {
			for (int j = 0; j < mSize; j++) {
				m.daddyVector[j][i] /= colWeight;
			}
		}
	}
	return m;
}

int Matrix::get_size() {
	return (int) (this->daddyVector.size());
}

Matrix::Matrix(int size, double p) : Matrix(size) {

	double pp = p/size;
	for (int i = 0; i < (int) daddyVector[0].size(); i++) {
		for (int j = 0; j < (int) daddyVector.size(); j++) {
			daddyVector[i][j] = pp;
		}
	}
}

Matrix::Matrix(int r, int c, double n) : Matrix(r, c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			daddyVector[i][j] = n;
		}
	}
}

Matrix operator*(double scale, const Matrix &lhs) {
	Matrix m = lhs;
	for (int i = 0; i < (int) lhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) lhs.daddyVector[i].size(); j++) {
			m.daddyVector[i][j] *= scale;
		}
	}
	return m;
}

double Matrix::getSumOfMatrixColumn(const Matrix &m) {
	int rowLen = (int) m.daddyVector.size();

	double sum = 0.0;
	for (int i = 0; i < rowLen; i++) {
		sum += m.daddyVector[i][0];
	}

	return sum;
}

void Matrix::scaleRank() {
	double mSum = Matrix::getSumOfMatrixColumn(*this);

	*this = (1/mSum) * (*this);
}

void Matrix::makeMToPercentage() {
	*this = 100 * (*this);
}

void Matrix::formatPrint() {
	int rowLen = (int) this->daddyVector.size();
	this->scaleRank();
	this->makeMToPercentage();

	// next two lines are credited to https://stackoverflow.com/a/49210615
	std::vector<char> alphabet(26);
	std::iota(alphabet.begin(), alphabet.end(), 'A');

	for (int i = 0 ; i < rowLen; i++) {
		cout << "Page " << alphabet[i] << ": " <<
			fixed << setprecision(2) <<
			this->daddyVector[i][0] <<
			"%" << endl;
	}

}