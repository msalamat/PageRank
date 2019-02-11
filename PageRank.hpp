//
// Created by Mohammad Salamat on 2019-02-08.
//

#ifndef ASSIGNMENT01_PAGERANK_HPP
#define ASSIGNMENT01_PAGERANK_HPP

#include <iostream>
#include "matrix.hpp"

class PageRank : Matrix {

	private:
		/** Random walk probability factor. */
		double p{0.85};
		/** 1 - p ! */
		double q{1 - this->p};
		/** a limit to keep infinite loops out */
		double emergencyLimit = 99999;
		/** a flag that is raised if the markov process goes for too long! */
		bool emergencyFlag = false;

	public:
		/**
		 * The default constructor!
		 */
		PageRank() = default;

		/**
		 * Get matrix object from text file.
		 * @param fileName the name of the file with the matrix in it
		 * @return A Matrix object consisting of the same matrix from the file
		 */
		Matrix getMatrixFromFile(const string &fileName);

		/**
		 * Uses the Markov Process to generate the final resulting matrix
		 * for the PageRank algorithm
		 *
		 * @param result the matrix that will be emerged as the final product
		 * @param M a matrix reference of M (from slides)
		 */
		void markovProcess(Matrix &result, const Matrix &M);

		/**
		 * Gets the class's p member
		 * @return data member p
		 */
		double getP() {
			return this->p;
		};

		/**
		 * Gets the class's q member
		 * @return data member q
		 */
		double getQ() {
			return this->q;
		};

		/**
		 * Gets the class's emergencyFlag member
		 * @return data member emergencyFlag
		 */
		bool getEmergencyFlag() {
			return this->emergencyFlag;
		}

		/** the name of the file with the matrix in it! */
		static const string fileName;

};


#endif //ASSIGNMENT01_PAGERANK_HPP
