//
// Created by Mohammad Salamat on 2019-01-28.
//
#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP

#include <vector>

using namespace std;
class Matrix {

	private:
		/** our 2d matrix */
		vector<vector<double>> daddyVector;
		/** a number is the same as another number as long as it is within this tolerance */
		constexpr static double tolerance = 0.001;

	public:
		/**
		 * A no parameter constructor for creating a matrix.
		 * Resulting matrix is a 1 by 1 matrix.
		 */
		Matrix();

		/**
		 * A one parameter constructor for creating a matrix.
		 * Resulting matrix is an "n by n" matrix.
		 * @param n the size of the matrix
		 */
		Matrix(int n);

		/**
		 * A two parameter constructor for creating a matrix.
		 * Resulting matrix is an "r by c" matrix.
		 *
		 * @param r number of rows
		 * @param c number of columns
		 */
		Matrix(int r, int c);

		/**
		 * A two parameter constructor for creating a matrix.
		 * Resulting matrix is a "size by size" matrix.
		 * @param p An array consisting of elements
		 * @param size The size of the array
		 */
		Matrix(double *p, int size);

		/**
		 * Sets the correct probability matrix
		 *
		 * @param size the size of the matrix
		 * @param p the probability
		 */
		Matrix(int size, double p);


		/**
		 * Makes and sets a matrix to whatever was specified
		 * @param r number of rows
		 * @param c number of columns
		 * @param n the number to set the matrix
		 */
		Matrix(int r, int c, double n);

		/**
		 * Free the matrix!
		 */
		~Matrix();

		/**
		 * Gets the sum of a matrix, using its columns
		 * @param m a matrix reference
		 * @return the sum of the columns
		 */
		static double getSumOfMatrixColumn(const Matrix &m);

		/**
		 * Prints the matrix to the screen.
		 */
		void printMatrix();

		/**
		 * Mutator - edit a specific cell in a matrix
		 * @param row the row of the cell
		 * @param column the column of the cell
		 * @param newNum the new number the cell is to become
		 */
		void set_value(int row, int column, double newNum);

		/**
		 * Accessor - get the value of a specific cell in a matrix
		 * @param row the row of the cell
		 * @param column the column of the cell
		 * @return the value in that cell
		 */
		double get_value(int row, int column);

		/**
		 * Gets the size of the matrix
		 * @return the size of the matrix
		 */
		int get_size();

		/**
		 * Zero out the matrix
		 */
		void clear();

		/**
		 * Check if a matrix has any full zeros in a column
		 * @param m a matrix
		 * @return The first occurance of a column with all zeroes
		 */
		int getColoumnIfAllZeroes(const Matrix &m);

		/**
		 * Gets the importance matrix, assuming *this is a connectivity matrix
		 * @return An importance matrix
		 */
		Matrix getImportanceMatrix();

		/**
		 * Scales the matrix by dividing by the sum of the col
		 */
		void scaleRank();

		/**
		 * As per the slides, multiplies by 100 to make it a percentage
		 */
		void makeMToPercentage();

		/**
		 * Formats the matrix and prints it out, nicely.
		 * A bit of a catch-all, and it includes the alphabet.
		 */
		void formatPrint();

		/**
		 * Swapping the matricies
		 * @param matrix the matrix
		 * @param rhs right hand side matrix
		 */
		void mySwap(Matrix& matrix, Matrix rhs);
		/**
		 * Overloaded << operator
		 * @param o  The ostream reference
		 * @param m The matrix reference
		 * @return The formatted o stream
		 */
		friend ostream &operator<<(ostream & o, Matrix & m);

		/**
		 * Overloaded == operator
		 * @param lhs The left matrix reference
		 * @param rhs The right matrix reference
		 * @return true if rhs == lhs, false otherwise
		 */
		friend bool operator== (const Matrix &lhs, const Matrix &rhs);

		/**
		 * Overloaded != operator
		 * @param lhs
		 * @param rhs
		 * @return the computed matrix
		 */
		friend bool operator!= (Matrix &lhs, Matrix &rhs);

		/**
		 * Overloading prefix operator (++m)
		 * @return the computed matrix
		 */
		Matrix& operator++(); // prefix

		/**
		 * Overloading the prefix operator (--m)
		 * @return the resulting matrix
		 */
		Matrix& operator--(); // prefix

		/**
		 * This is overloading the postfix operator (m++)
		 * @return the computed matrix
		 */
		Matrix operator++(int); // postfix


		/**
		 * This is overloading the postfix operator (m--)
		 * @return The resulting matrix
		 */

		Matrix operator--(int); // postfix

		/**
		 * Overloading the assignment operator
		 * @param rhs a matrix
		 * @return the resulting matrix
		 */
		Matrix& operator=(Matrix rhs);

		/**
		 * Overloaded += operator
		 * @param rhs matrix on the right side
		 * @return the resulting matrix
		 */
		Matrix& operator+=(const Matrix& rhs);

		/**
		 * Overloaded + operator
		 * @param lhs left hand side matrix
		 * @param rhs right hand side matrix
		 * @return the resulting matrix
		 */
		friend Matrix operator+(Matrix lhs, const Matrix & rhs);

		/**
		 * Overloading the -= operator
		 * @param rhs right hand side matrix
		 * @return the resulting matrix
		 */
		Matrix& operator-=(const Matrix& rhs);

		/**
		 * Overloaded - operator
		 * @param lhs left hand side matrix
		 * @param rhs right hand side matrix
		 * @return the resulting matrix
		 */
		friend Matrix operator-(Matrix lhs, const Matrix &rhs);

		/**
		 * Overloading *= operator
		 * @param rhs right hand side matrix
		 * @return the resulting matrix
		 */
		Matrix& operator*=(const Matrix &rhs);

		/**
		 * Overloading the * operator
		 *
		 * @param lhs left hand side matrix
		 * @param rhs right hand side matrix
		 * @return the resulting matrix
		 */
		friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);

		/**
		 * Overloading the * operator to scale a matrix
		 * @param scale what to multiply the matrix by
		 * @param lhs the left hand side matrix
		 * @return the resulting matrix
		 */
		friend Matrix operator*(double scale, const Matrix &lhs);
};

#endif //ASSIGNMENT01_MATRIX_HPP