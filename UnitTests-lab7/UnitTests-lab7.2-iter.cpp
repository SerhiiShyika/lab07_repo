#include "pch.h"
#include "CppUnitTest.h"

#define main lab_7_2_iter_main
#define Create Lab72IterCreate
#define Print Lab72IterPrint
#define SortDiagonal Lab72IterSortDiagonal
#include "..\Lab-07.2 it\Lab-07.2 it.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestslab_7_2_iter
{
	TEST_CLASS(UnitTestslab_7_2_iter)
	{
	public:
		TEST_METHOD(SortDiagonalOrdersDiagonalDescending)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][0] = 3;
			matrix[1][1] = -1;
			matrix[2][2] = 7;
			matrix[3][3] = 0;

			Lab72IterSortDiagonal(matrix, 4);

			Assert::AreEqual(7, matrix[0][0]);
			Assert::AreEqual(3, matrix[1][1]);
			Assert::AreEqual(0, matrix[2][2]);
			Assert::AreEqual(-1, matrix[3][3]);
		}

		TEST_METHOD(SortDiagonalLeavesOffDiagonalElementsUnchanged)
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

			Lab72IterSortDiagonal(matrix, 4);

			Assert::AreEqual(11, matrix[0][1]);
			Assert::AreEqual(-4, matrix[1][0]);
			Assert::AreEqual(8, matrix[2][3]);
			Assert::AreEqual(15, matrix[3][2]);
		}

		TEST_METHOD(CreateFillsRequestedMatrixWithinBounds)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};

			Lab72IterCreate(matrix, 3, 5, 5);

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(5, matrix[i][j]);
		}

		TEST_METHOD(SortDiagonalHandlesSingleElementMatrix)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {};
			matrix[0][0] = 42;

			Lab72IterSortDiagonal(matrix, 1);

			Assert::AreEqual(42, matrix[0][0]);
		}
	};
}
