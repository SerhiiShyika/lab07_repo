#include "pch.h"
#include "CppUnitTest.h"

#define main lab_7_1_rec_main
#define Create RecursiveCreate
#define Print RecursivePrint
#define Copy RecursiveCopy
#define MatchesCriteria RecursiveMatchesCriteria
#define Calc RecursiveCalc
#define NeedSwap RecursiveNeedSwap
#define Change RecursiveChange
#define SortPass RecursiveSortPass
#define Sort RecursiveSort
#include "..\Lab-07.1 rec\Lab-07.1 rec.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestslab_7_1_rec
{
	TEST_CLASS(UnitTestslab_7_1_rec)
	{
	public:
		TEST_METHOD(MatchesCriteriaChecksParityAndPosition)
		{
			Assert::IsTrue(MatchesCriteria(8, 1, 2));
			Assert::IsFalse(MatchesCriteria(7, 1, 2));
			Assert::IsFalse(MatchesCriteria(8, 0, 0));
			Assert::IsFalse(MatchesCriteria(8, 3, 3));
		}

		TEST_METHOD(CopyRecursivelyCopiesEveryElement)
		{
			int source[ROWS][COLS] =
			{
				{1, 2, 3, 4, 5},
				{6, 7, 8, 9, 10},
				{11, 12, 13, 14, 15},
				{16, 17, 18, 19, 20},
				{21, 22, 23, 24, 25},
				{26, 27, 28, 29, 30},
				{31, 32, 33, 34, 35},
				{36, 37, 38, 39, 40}
			};
			int destination[ROWS][COLS] = {};

			Copy(source, destination, 0, 0);

			for (int i = 0; i < ROWS; i++)
				for (int j = 0; j < COLS; j++)
					Assert::AreEqual(source[i][j], destination[i][j]);
		}

		TEST_METHOD(CalcRecursivelyCountsSumsAndReplacesMatchingElements)
		{
			int matrix[ROWS][COLS] =
			{
				{2, 4, 6, 8, 10},
				{12, 14, 16, 18, 20},
				{1, 3, 5, 7, 9},
				{22, 24, 26, 28, 30},
				{1, 3, 5, 7, 9},
				{1, 3, 5, 7, 9},
				{1, 3, 5, 7, 9},
				{1, 3, 5, 7, 9}
			};
			int count = 0;
			int sum = 0;

			Calc(matrix, 0, 0, count, sum);

			Assert::AreEqual(11, count);
			Assert::AreEqual(180, sum);
			Assert::AreEqual(2, matrix[0][0]);
			Assert::AreEqual(0, matrix[0][1]);
			Assert::AreEqual(8, matrix[0][3]);
			Assert::AreEqual(0, matrix[1][4]);
			Assert::AreEqual(0, matrix[3][4]);
			Assert::AreEqual(28, matrix[3][3]);
		}

		TEST_METHOD(SortRecursivelyOrdersRowsByTheSpecifiedKeys)
		{
			int matrix[ROWS][COLS] =
			{
				{2, 9, 5, 0, 0},
				{1, 9, 5, 0, 1},
				{1, 8, 9, 1, 0},
				{1, 8, 7, 1, 1},
				{3, 0, 0, 0, 0},
				{4, 0, 0, 0, 0},
				{5, 0, 0, 0, 0},
				{6, 0, 0, 0, 0}
			};

			Sort(matrix, 0);

			const int expected[4][3] =
			{
				{1, 9, 5},
				{1, 8, 9},
				{1, 8, 7},
				{2, 9, 5}
			};

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(expected[i][j], matrix[i][j]);
		}
	};
}

