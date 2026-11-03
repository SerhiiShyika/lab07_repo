#include "pch.h"
#include "CppUnitTest.h"

#define main lab_7_2_rec_main
#define Create Lab72RecCreate
#define Print Lab72RecPrint
#define FindMaxDiagonal Lab72RecFindMaxDiagonal
#define SortDiagonal Lab72RecSortDiagonal
#include "..\Lab-07.2 rec\Lab-07.2 rec.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestslab_7_2_rec
{
	TEST_CLASS(UnitTestslab_7_2_rec)
	{
	public:
		TEST_METHOD(SortDiagonalRecursivelyOrdersDiagonalDescending)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][0] = 3;
			matrix[1][1] = -1;
			matrix[2][2] = 7;
			matrix[3][3] = 0;

			Lab72RecSortDiagonal(matrix, 4, 0);

			Assert::AreEqual(7, matrix[0][0]);
			Assert::AreEqual(3, matrix[1][1]);
			Assert::AreEqual(0, matrix[2][2]);
			Assert::AreEqual(-1, matrix[3][3]);
		}

		TEST_METHOD(SortDiagonalRecursivelyLeavesOffDiagonalElementsUnchanged)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][1] = 11;
			matrix[1][0] = -4;
			matrix[2][3] = 8;
			matrix[3][2] = 15;
			matrix[0][0] = 1;
			matrix[1][1] = 2;
			matrix[2][2] = 3;
			matrix[3][3] = 4;

			Lab72RecSortDiagonal(matrix, 4, 0);

			Assert::AreEqual(11, matrix[0][1]);
			Assert::AreEqual(-4, matrix[1][0]);
			Assert::AreEqual(8, matrix[2][3]);
			Assert::AreEqual(15, matrix[3][2]);
		}

		TEST_METHOD(FindMaxDiagonalReturnsLargestRemainingIndex)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][0] = 3;
			matrix[1][1] = -1;
			matrix[2][2] = 7;
			matrix[3][3] = 0;

			const int maxIndex = Lab72RecFindMaxDiagonal(matrix, 4, 1, 0);

			Assert::AreEqual(2, maxIndex);
		}

		TEST_METHOD(CreateRecursivelyFillsRequestedMatrixWithinBounds)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};

			Lab72RecCreate(matrix, 3, 5, 5, 0, 0);

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(5, matrix[i][j]);
		}

		TEST_METHOD(SortDiagonalRecursivelyHandlesSingleElementMatrix)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][0] = 42;

			Lab72RecSortDiagonal(matrix, 1, 0);

			Assert::AreEqual(42, matrix[0][0]);
		}
	};
}
