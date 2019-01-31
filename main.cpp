#include <iostream>
#include "matrix.cpp"

int main() {
    Matrix myMatrix2(2, 3);
    Matrix myMatrix1(3, 2);

	myMatrix1.set_value(0,0, 2);
	myMatrix1.set_value(0,1, 1);
	myMatrix1.set_value(1,0, 3);
	myMatrix1.set_value(1,1, 4);
	myMatrix1.set_value(2,0, 5);
	myMatrix1.set_value(2,1, 6);





	myMatrix2.set_value(0,0, 1);
	myMatrix2.set_value(0,1, 3);
	myMatrix2.set_value(0,2, 6);

	myMatrix2.set_value(1,0, 2);
	myMatrix2.set_value(1,1, 4);
	myMatrix2.set_value(1,2, 5);

	Matrix myMatrix3{myMatrix1 * myMatrix2};
	cout << myMatrix3; // YAY IT WORKS
//
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

    return 0;

}