//
// Created by Mohammad Salamat on 2019-01-28.
//
#include <iostream>
#include <cmath>
#include "matrix.hpp"

const double tolerance = 0.0001;

/**
 * A no parameter constructor for creating a matrix.
 * Resulting matrix is a 1 by 1 matrix.
 */
Matrix::Matrix() {}

/**
 * A one parameter constructor for creating a matrix.
 * Resulting matrix is an "n by n" matrix.
 * @param
 */
Matrix::Matrix(int n) {

	if (n <= 0) {
		cerr << "cannot be <= zero, come on!!!!!!" << endl;
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		vector<double> babyVector;
		for (int j = 0; j < n; j++) {
			babyVector.push_back(0.0);
		}
		daddyVector.push_back(babyVector);
	}
}

/**
 * A two parameter constructor for creating a matrix.
 * Resulting matrix is an "r by c" matrix.
 *
 * @param r number of rows
 * @param c number of columns
 */
Matrix::Matrix(int r, int c) {

	if (r <= 0 || c <= 0) {
		cerr << "cannot be <= zero, come on." << endl;
		exit(1);
	}

	for (int i = 0; i < r; i++) {
		vector<double> babyVector;
		for (int j = 0; j < c; j++) {
			babyVector.push_back(0.0);
		}
		daddyVector.push_back(babyVector);
	}
}

/**
 * A two parameter constructor for creating a matrix.
 * Resulting matrix is a "size by size" matrix.
 * @param p An array consisting of elements
 * @param size The size of the array
 */
Matrix::Matrix(double *p, int size) {
	if (!isSquare(size)) {
		throw invalid_argument("Not a square, try again.");
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

/**
 * Prints the matrix to the screen.
 */
void Matrix::printMatrix() {

	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			cout << daddyVector[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * Mutator - edit a specific cell in a matrix
 * @param row the row of the cell
 * @param column the column of the cell
 * @param newNum the new number the cell is to become
 */
void Matrix::set_value(const int row, const int column, const double newNum) {
	daddyVector[row][column] = newNum;
}

/**
 * Accessor - get the value of a specific cell in a matrix
 * @param row the row of the cell
 * @param column the column of the cell
 * @return the value in that cell
 */
double Matrix::get_value(int row, int column) {
	return daddyVector[row][column];
}

/**
 * Zero out the matrix
 */
void Matrix::clear() {
	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			daddyVector[i][j] = 0.0;
		}
	}
}

/**
 * Destructor
 */
Matrix::~Matrix() {
	for (int i = 0; i < (int) daddyVector.size(); i++) {
		daddyVector[i].clear();
		daddyVector[i].shrink_to_fit();
	}
	daddyVector.clear();
	daddyVector.shrink_to_fit();
}

/**
 * Overloaded << operator
 * @param o  The ostream reference
 * @param m The matrix reference
 * @return The formatted o stream
 */
ostream &operator<<(ostream & o, Matrix & m)  {

	for (unsigned long i = 0; i < m.daddyVector.size(); i++) {
		for (unsigned long j = 0; j < m.daddyVector[i].size(); j++){
			o << m.daddyVector[i][j] << "\t";
		}
		o << endl;
	}
	return o;
}

/**
 * Overloaded == operator
 * @param lhs The left matrix reference
 * @param rhs The right matrix reference
 * @return true if rhs == lhs, false otherwise
 */
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
			if (biggerNum > smallerNum + tolerance)
				return false;
		}
	}

	return true;
}

/**
 * Overloaded != operator
 * @param lhs
 * @param rhs
 * @return the computed matrix
 */
bool operator!=(Matrix &lhs, Matrix &rhs) {
	 //return !operator==(lhs, rhs); both work
	 return !(lhs==rhs);
}

/**
 * Overloading prefix operator (++m)
 * @return the computed matrix
 */
Matrix &Matrix::operator++() {

	for (int i = 0; i < (int) daddyVector.size(); i++) {
		for (int j = 0; j < (int) daddyVector[i].size(); j++) {
			++daddyVector[i][j];
		}
	}
	return *this;
}

/**
 * This is overloading the postfix operator (m++)
 * @return the computed matrix
 */
Matrix Matrix::operator++(int) {
	Matrix old(*this);
	operator++();
	return old;
}

/**
 * Overloading the prefix operator (--m)
 * @return the resulting matrix
 */
Matrix &Matrix::operator--() {
	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		for (unsigned long j = 0; j < daddyVector[i].size(); j++) {
			--daddyVector[i][j];
		}
	}
	return *this;
}

/**
 * This is overloading the postfix operator (m--)
 * @return The resulting matrix
 */
Matrix Matrix::operator--(int) {
	Matrix old(*this);
	operator--();
	return old;
}

/**
 * Overloading the assignment operator
 * @param rhs a matrix
 * @return the resulting matrix
 */
Matrix& Matrix::operator=(Matrix rhs) {
	mySwap(*this, rhs);
	return *this;
}

/**
 * Swapping the matricies
 * @param matrix the matrix
 * @param rhs right hand side matrix
 */
void Matrix::mySwap(Matrix &matrix, Matrix rhs) {
	for (int i = 0; i < (int) rhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) rhs.daddyVector[i].size(); j++) {
			matrix.daddyVector[i][j] = rhs.daddyVector[i][j];
		}
	}
}

/**
 * Overloaded += operator
 * @param rhs matrix on the right side
 * @return the resulting matrix
 */
Matrix& Matrix::operator+=(const Matrix &rhs) {

	*this = *this + rhs;

	return *this;
}

/**
 * Overloaded + operator
 * @param lhs left hand side matrix
 * @param rhs right hand side matrix
 * @return the resulting matrix
 */
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
 /**
  * Overloading the -= operator
  * @param rhs right hand side matrix
  * @return the resulting matrix
  */
Matrix &Matrix::operator-=(const Matrix &rhs) {
	*this = *this - rhs;

	return *this;
}

/**
 * Overloaded - operator
 * @param lhs left hand side matrix
 * @param rhs right hand side matrix
 * @return the resulting matrix
 */
Matrix operator-(Matrix lhs, const Matrix &rhs) {
	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		throw invalid_argument("not same size error");
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		throw invalid_argument("not same size error");

	for (unsigned long i = 0; i < lhs.daddyVector.size(); i++) {
		for (unsigned int j = 0; j < lhs.daddyVector[i].size(); j++) {
			lhs.daddyVector[i][j] -= rhs.daddyVector[i][j];
		}
	}
	return lhs;

}

/**
 * Overloading *= opeartor
 * @param rhs right hand side matrix
 * @return the resulting matrix
 */
Matrix &Matrix::operator*=(const Matrix &rhs) {
	*this = *this - rhs;

	return *this;
}

/**
 * Overloading the * operator
 *
 * @param lhs left hand side matrix
 * @param rhs right hand side matrix
 * @return the resulting matrix
 */
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

/**
 * Gets the importance matrix
 * @return An importance matrix
 */
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

/**
 * Gets the size of the matrix
 * @return the size of the matrix
 */
int Matrix::get_size() {
	return (int) (this->daddyVector.size());
}

/**
 * Sets the correct probability matrix
 *
 * @param size the size of the matrix
 * @param p the probability
 */
Matrix::Matrix(int size, double p) : Matrix(size) {

	double pp = p/size;
	for (int i = 0; i < (int) daddyVector[0].size(); i++) {
		for (int j = 0; j < (int) daddyVector.size(); j++) {
			daddyVector[i][j] = pp;
		}
	}
}

/**
 * Makes and sets a matrix to whatever was specified
 * @param r number of rows
 * @param c number of columns
 * @param n the number to set the matrix
 */
Matrix::Matrix(int r, int c, double n) : Matrix(r, c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			daddyVector[i][j] = n;
		}
	}
}

/**
 * Overloading the * operator to scale
 * @param scale what to multiply the matrix by
 * @param lhs the left hand side matrix
 * @return the resulting matrix
 */
Matrix operator*(double scale, const Matrix &lhs) {
	Matrix m = lhs;
	for (int i = 0; i < (int) lhs.daddyVector.size(); i++) {
		for (int j = 0; j < (int) lhs.daddyVector[i].size(); j++) {
			m.daddyVector[i][j] *= scale;
		}
	}
	return m;
}


/**
 * Determines whether a number is a square number
 * @param n
 * @return
 */
bool isSquare(int n) {
	int sq = (int) sqrt(n);
	return sq*sq == n;
}
