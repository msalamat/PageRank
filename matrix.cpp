//
// Created by Mohammad Salamat on 2019-01-28.
//
#include <iostream>
#include <math.h>       /* sqrt */
#include "matrix.hpp"

/**
 * Constructor 1
 */
Matrix::Matrix() {}


/**
 * Constructor 2
 * @param n
 */
Matrix::Matrix(int n) {

	if (n <= 0) {
		cerr << "cannot be <= zero, come on." << endl;
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
 * Constructor 3
 *
 * @param r
 * @param c
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
 * Print the matrix to the screen
 */
void Matrix::printMatrix() {

	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		for (unsigned long j = 0; j < daddyVector[i].size(); j++) {
			cout << daddyVector[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * Constructor 4
 * @param p
 * @param size
 */
Matrix::Matrix(double *p, unsigned long long size) {
	if (!isSquare(size)) {
		throw invalid_argument("Not a square, try again.");
	}

	int counter = 0;

	for (int i = 0; i < sqrt(size); i++) {

		vector<double> babyVector;

		for (int j = 0; j < sqrt(size); j++) {
			babyVector.push_back(*(p+counter));
			counter++;
		}

		daddyVector.push_back(babyVector);
	}
}

/**
 * Mutator - edit a specific cell in a matrix
 * @param row
 * @param column
 * @param newNum
 */
void Matrix::set_value(const int row, const int column, const double newNum) {
	daddyVector[row][column] = newNum;
}

/**
 * Accessor - get the value of a specific cell in a matrix
 * @param row
 * @param column
 * @return
 */
double Matrix::get_value(int row, int column) {
	return daddyVector[row][column];
}

/**
 * Zero out the matrix
 */
void Matrix::clear() {
	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		for (unsigned long j = 0; j < daddyVector[i].size(); j++) {
			daddyVector[i][j] = 0.0;
		}
	}
}

/**
 * Destructor
 */
Matrix::~Matrix() {
//	daddyVector.clear();
//	daddyVector.shrink_to_fit();
	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		daddyVector[i].clear();
		daddyVector[i].shrink_to_fit();
	}
	daddyVector.clear();
	daddyVector.shrink_to_fit();
}

/**
 * Starting to get fuzzy here
 * @param o
 * @param m
 * @return
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
 * What am I doing..
 * @param lhs
 * @param rhs
 * @return
 */
bool operator==(const Matrix &lhs, const Matrix &rhs) {

	// size of daddy, i.e. number of rows
	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		return false;
	// row size
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		return false;

	double smallerNum, biggerNum;

	for (unsigned long i = 0; i < lhs.daddyVector.size(); i++) {
		for (unsigned long j = 0; j < lhs.daddyVector[i].size(); j++) {
			smallerNum = min(lhs.daddyVector[i][j], rhs.daddyVector[i][j]);
			biggerNum = max(lhs.daddyVector[i][j], rhs.daddyVector[i][j]);
			if (biggerNum >
				smallerNum + 0.1) // I don't think we actually need to include  || biggerNum < smallerNum - 0.1)
				return false;
		}
	}

	return true;
}

/**
 * Oh my god..
 * @param lhs
 * @param rhs
 * @return
 */
bool operator!=(Matrix &lhs, Matrix &rhs) {
	 //return !operator==(lhs, rhs); both work
	 return !(lhs==rhs);
}

/**
 * THIS IS THE PREFIX OPERATOR, I.E. ++myMatrix
 * @return
 */
Matrix &Matrix::operator++() {

	for (unsigned long i = 0; i < daddyVector.size(); i++) {
		for (unsigned long j = 0; j < daddyVector[i].size(); j++) {
			++daddyVector[i][j];
		}
	}
	return *this;
}

/**
 * THIS IS THE PREFIX OPERATOR, I.E. myMatrix++
 * ASK SOMEONE WHAT THE DUMMY IS FOR (SOMETHING ABOUT DISTINGUISHING IT)
 * @return
 */
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

// don't forget to ask about this again
Matrix Matrix::operator--(int) {
	Matrix old(*this);
	operator--();
	return old;
}

Matrix& Matrix::operator=(Matrix rhs) {
	mySwap(*this, rhs);
	return *this;
}

/**
 *
 * @param matrix
 * @param rhs
 */
void Matrix::mySwap(Matrix &matrix, Matrix rhs) {
	for (unsigned long i = 0; i < rhs.daddyVector.size(); i++) {
		for (unsigned long j = 0; j < rhs.daddyVector[i].size(); j++) {
			matrix.daddyVector[i][j] = rhs.daddyVector[i][j];
		}
	}
}

Matrix& Matrix::operator+=(const Matrix &rhs) {

	*this = *this + rhs;

	return *this;
}

/*
 * "Friend to the left side matrix, friends with object on left"
 */
Matrix operator+(Matrix lhs, const Matrix &rhs) {

	if (lhs.daddyVector.size() != rhs.daddyVector.size())
		throw ("not same size error");
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		throw ("not same size error");

	for (unsigned long i = 0; i < lhs.daddyVector.size(); i++) {
		for (unsigned long j = 0; j < lhs.daddyVector[i].size(); j++) {
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
		throw ("not same size error");
	if (lhs.daddyVector[0].size() != rhs.daddyVector[0].size())
		throw ("not same size error");

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
		throw ("col lhs must == row of rhs");
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
 * Determines whether a number is a square number
 * @param n
 * @return
 */
bool isSquare(int n) {
	int sq = (int) sqrt(n);
	return sq*sq == n;
}
