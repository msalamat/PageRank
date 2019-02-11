#include <iostream>
#include <fstream>
#include <sstream>
#include "PageRank.hpp"

int main() {

	auto *pr = new PageRank();

	Matrix connectivityMatrix = pr->getMatrixFromFile(PageRank::fileName);

	// set up the matrix equation from slides
	Matrix S = connectivityMatrix.getImportanceMatrix();
	Matrix q{S.get_size(), pr->getQ()};
	Matrix M = (pr->getP() * S) + q;
	Matrix rank(S.get_size(), 1, 1); // 4x1 col (rank matrix)

	// begin markov process
	Matrix result = rank;
	pr->markovProcess(result, M);

	if (pr->getEmergencyFlag()) { // just in case, since I am not clear on the underlying math
		std::cerr << "There seemed to be an infinite loop, this is an emergency exit!" << std::endl;
		exit(1);
	}

	result.formatPrint();
}

