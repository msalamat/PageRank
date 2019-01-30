//
// Created by Mohammad Salamat on 2019-01-28.
//
#include <iostream>
#include "matrix.hpp"

Matrix::Matrix() {
}

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

void Matrix::printMatrix() {

	for (int i = 0; i < daddyVector.size(); i++) {
		for (int j = 0; j < daddyVector[i].size(); j++) {
			cout << daddyVector[i][j] << " ";
		}
		cout << endl;
	}
}


