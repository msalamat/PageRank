//
// Created by Mohammad Salamat on 2019-01-28.
//

#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP

#include <vector>

bool isSquare(int n);

using namespace std;
class Matrix {

	private:
		vector<vector<double>> daddyVector; // by default it is 1d

	public:
		Matrix();
		Matrix(int n);
		Matrix(int r, int c);
		Matrix(double *p, int size);
		Matrix(int size, double p);
		Matrix(int r, int c, double n);

		~Matrix();

		void printMatrix();
		void set_value(int row, int column, double newNum);
		double get_value(int row, int column);
		int get_size();
		void clear();
		int getColoumnIfAllZeroes(const Matrix &m);
		Matrix getImportanceMatrix();

		friend ostream &operator<<(ostream & o, Matrix & m);
		friend bool operator== (const Matrix &lhs, const Matrix &rhs);
		friend bool operator!= (Matrix &lhs, Matrix &rhs);
		Matrix& operator++(); // prefix
		Matrix& operator--(); // prefix
		Matrix operator++(int); // postfix

		Matrix operator--(int); // postfix

		Matrix& operator=(Matrix rhs);
		// += , + , -=, -
		Matrix& operator+=(const Matrix& rhs);

		friend Matrix operator+(Matrix lhs, const Matrix & rhs);
		Matrix& operator-=(const Matrix& rhs);

		friend Matrix operator-(Matrix lhs, const Matrix &rhs);
		Matrix& operator*=(const Matrix &rhs);

		friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);

		friend Matrix operator*(double scale, const Matrix &lhs);

		void mySwap(Matrix& matrix, Matrix rhs);
};

#endif //ASSIGNMENT01_MATRIX_HPP

// inline functions work liek a macro. transform all your method calls to the actual function
// why is it good, bad