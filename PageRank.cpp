//
// Created by Mohammad Salamat on 2019-02-08.
//

#include <fstream>
#include <sstream>
#include "PageRank.hpp"

const string PageRank::fileName = "connectivity.txt";

Matrix PageRank::getMatrixFromFile(const string &fileName) {
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
		cerr << "Oops! Didn't get the file! If you compiled with g++ (via command line), " << endl;
		cerr << "keep in mind that this program assumes the executable is in" << endl;
		cerr << "/cmake-build-debug, and that connectivity.txt is in the root (/)." << endl;
		cerr <<  "If it is not, simply move the executable in that folder" << endl;
		exit(1);
	}

	double *arr = &listOfNumbers[0];
	int mSize = (int) listOfNumbers.size();
	Matrix maMatrix(arr, mSize);

	return maMatrix;
}

void PageRank::markovProcess(Matrix &result, const Matrix &M) {
	int emergencyCounter = 0;

	while (true) {
		Matrix oldMatrix = result;
		result = M * result;

		if (result==oldMatrix)
			return;

		if (++emergencyCounter == this->emergencyLimit) {
			this->emergencyFlag = true;
			return;
		}
	}
}