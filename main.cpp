#include <iostream>
#include "matrix.cpp"

int main() {
    Matrix myMatrix1(3, 3);
    Matrix myMatrix2(3, 3);

    cout << "Using the overloaded << operator" << endl;

	myMatrix1++;
	--myMatrix2;
	myMatrix2--;
    cout << myMatrix1 << endl;
    cout << myMatrix2 << endl;

	myMatrix1 = myMatrix2;
	cout << myMatrix1 << endl;

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

    return 0;

}