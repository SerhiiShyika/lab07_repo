
// Lab-07.1-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 7.1
// Пошук елементів та впорядкування рядків матриці
// Варіант 31 — ітераційний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 8;
const int COLS = 5;

// Створення матриці
void Create(int R[][COLS], const int rows,
    const int Low, const int High)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            R[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці
void Print(const int R[][COLS], const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << setw(5) << R[i][j];

        cout << endl;
    }

    cout << endl;
}

// Копіювання початкової матриці
void Copy(const int source[][COLS],
    int destination[][COLS], const int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            destination[i][j] = source[i][j];
}

// Перевірка умови варіанта
bool MatchesCriteria(const int value,
    const int i, const int j)
{
    return !(value % 2 != 0 ||
        (i % 3 == 0 && j % 3 == 0));
}

// Підрахунок і заміна елементів нулями
void Calc(int R[][COLS], const int rows,
    int& count, int& sum)
{
    count = 0;
    sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (MatchesCriteria(R[i][j], i, j))
            {
                count++;
                sum += R[i][j];
                R[i][j] = 0;
            }
        }
    }
}

// Перевірка порядку двох сусідніх рядків
bool NeedSwap(const int R[][COLS], const int i)
{
    if (R[i][0] != R[i + 1][0])
        return R[i][0] > R[i + 1][0];

    if (R[i][1] != R[i + 1][1])
        return R[i][1] < R[i + 1][1];

    return R[i][2] < R[i + 1][2];
}

// Обмін двох рядків
void Change(int R[][COLS],
    const int row1, const int row2)
{
    for (int j = 0; j < COLS; j++)
    {
        int temp = R[row1][j];
        R[row1][j] = R[row2][j];
        R[row2][j] = temp;
    }
}

// Сортування рядків
void Sort(int R[][COLS], const int rows)
{
    for (int k = 0; k < rows - 1; k++)
    {
        for (int i = 0; i < rows - 1 - k; i++)
        {
            if (NeedSwap(R, i))
                Change(R, i, i + 1);
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int Low = 4;
    const int High = 51;

    int R[ROWS][COLS];
    int R1[ROWS][COLS];
    int R2[ROWS][COLS];

    Create(R, ROWS, Low, High);

    Copy(R, R1, ROWS);
    Copy(R, R2, ROWS);

    cout << "Original matrix:" << endl;
    Print(R, ROWS);

    // Завдання 1
    int count, sum;

    Calc(R1, ROWS, count, sum);

    cout << "Task 1:" << endl;
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    cout << "Modified matrix:" << endl;
    Print(R1, ROWS);

    // Завдання 2
    Sort(R2, ROWS);

    cout << "Task 2:" << endl;
    cout << "Sorted matrix:" << endl;
    Print(R2, ROWS);

    return 0;
}
