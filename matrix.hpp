//
// Created by Mohammad Salamat on 2019-01-28.
//

#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP

#include <vector>

using namespace std;
class Matrix {

	private:
		vector<vector<double>> daddyVector; // by default it is 1d
	public:
		Matrix();
		Matrix(int n);
		Matrix(int r, int c);






		Matrix(double *p);

		void printMatrix();

};


#endif //ASSIGNMENT01_MATRIX_HPP
