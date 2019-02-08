#include <iostream>
#include <fstream>
#include <sstream>
#include "matrix.hpp"

Matrix getMatrixFromFile(const string &fileName) {

	string formattedFileName = "../" + fileName;

	vector<double> listOfNumbers;

	ifstream myFile(formattedFileName);
	string line;

	if (myFile.is_open()) {
		while(getline(myFile, line)) {
			std::istringstream stream(line);
			std::string letter;
			while (stream >> letter) { // go through the line and get each digit
				listOfNumbers.push_back(std::stod(letter));
			}
		}
	} else {
		cout << "Oops! Lol!! Didn't get the file!" << endl;
	}

	double *arr = &listOfNumbers[0];
	int mSize = (int) listOfNumbers.size();
	Matrix maMatrix(arr, mSize);

	return maMatrix;
}

int main() {
	string fileName = "connectivity.txt";
	Matrix connectivityMatrix = getMatrixFromFile(fileName);
	Matrix S = connectivityMatrix.getImportanceMatrix();

	double p{0.85};
	Matrix q(S.get_size(), 1-p);
	Matrix M = (p*S) + q;

	Matrix rank(S.get_size(), 1, 1); // 4x1 col (rank)

	vector<double> v;

	Matrix test = rank;

	while (true) {
		Matrix oldMatrix = test;
		test = M * test;
		if (test==oldMatrix) {
			break;
		}
	}

	cout << test;

	cout << endl;
	return 0;


}

