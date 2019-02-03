#include <iostream>
#include <fstream>
#include <sstream>
#include "matrix.cpp"

Matrix getMatrixFromFile(const string &fileName) {


	string formattedFileName = "../" + fileName;

	//cout << formattedFileName << endl;
	vector<double> listOfNumbers;

	ifstream myFile(formattedFileName);
	string line;
	if (myFile.is_open()) {
		while(getline(myFile, line)) {
			std::istringstream stream(line);
			std::string letter;
			while (stream >> letter) {
				listOfNumbers.push_back(std::stod(letter));
			}
		}
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
	// here I have the connectivity matrix. Now I want to make it into an importance matrix
	//Matrix importanceMatrix = getImportanceMatrix(connectivityMatrix);
	cout << endl;
	return 0;
//	Matrix connectivity_matrix(4,4);
//	connectivity_matrix.set_value(0,0,0);
//	connectivity_matrix.set_value(0,1,1);
//	connectivity_matrix.set_value(0,1,1);
//	connectivity_matrix.set_value(0,1,0);
//
//	connectivity_matrix.set_value(1,1,0);
//	connectivity_matrix.set_value(1,0,0);
//	connectivity_matrix.set_value(1,1,0);
//	connectivity_matrix.set_value(1,0,0);
//
//	connectivity_matrix.set_value(2,0,0);
//	connectivity_matrix.set_value(2,0,0);
//	connectivity_matrix.set_value(2,0,0);
//	connectivity_matrix.set_value(2,0,0);


//    Matrix myMatrix2(2, 3);
//    Matrix myMatrix1(3, 2);
//
//	myMatrix1.set_value(0,0, 2);
//	myMatrix1.set_value(0,1, 1);
//	myMatrix1.set_value(1,0, 3);
//	myMatrix1.set_value(1,1, 4);
//	myMatrix1.set_value(2,0, 5);
//	myMatrix1.set_value(2,1, 6);
//
//
//
//
//
//	myMatrix2.set_value(0,0, 1);
//	myMatrix2.set_value(0,1, 3);
//	myMatrix2.set_value(0,2, 6);
//
//	myMatrix2.set_value(1,0, 2);
//	myMatrix2.set_value(1,1, 4);
//	myMatrix2.set_value(1,2, 5);
//
//	Matrix myMatrix3{myMatrix1 * myMatrix2};
//	cout << myMatrix3; // YAY IT WORKS

//    cout << myMatrix1 << endl;
//    cout << myMatrix2 << endl;


//    cout << endl;
//    cout << "Now attemping to check for equality." << endl;
//	if (myMatrix1 != myMatrix2) {
//		cout << "Matrix 1 and 2 are not equal!" << endl;
//	} else {
//		cout << "Matrix 1 and 2 are equal!" << endl;
//	}

//    double foo[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//    Matrix myMatrix2(foo, 9);
//    myMatrix2.printMatrix();
	//myMatrix.printMatrix();

}

