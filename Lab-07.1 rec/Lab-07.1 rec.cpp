
// Lab-07.1-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 7.1
// Пошук елементів та впорядкування рядків матриці
// Варіант 31 — рекурсивний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 8;
const int COLS = 5;

// Рекурсивне створення матриці
void Create(int R[][COLS], const int i, const int j,
    const int Low, const int High)
{
    if (i >= ROWS)
        return;

    R[i][j] = Low + rand() % (High - Low + 1);

    if (j < COLS - 1)
        Create(R, i, j + 1, Low, High);
    else
        Create(R, i + 1, 0, Low, High);
}

// Рекурсивне виведення матриці
void Print(const int R[][COLS], const int i, const int j)
{
    if (i >= ROWS)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << R[i][j];

    if (j < COLS - 1)
        Print(R, i, j + 1);
    else
    {
        cout << endl;
        Print(R, i + 1, 0);
    }
}

// Рекурсивне копіювання матриці
void Copy(const int source[][COLS],
    int destination[][COLS],
    const int i, const int j)
{
    if (i >= ROWS)
        return;

    destination[i][j] = source[i][j];

    if (j < COLS - 1)
        Copy(source, destination, i, j + 1);
    else
        Copy(source, destination, i + 1, 0);
}

// Перевірка критерію варіанта
bool MatchesCriteria(const int value,
    const int i, const int j)
{
    return !(value % 2 != 0 ||
        (i % 3 == 0 && j % 3 == 0));
}

// Рекурсивний підрахунок та заміна нулями
void Calc(int R[][COLS], const int i, const int j,
    int& count, int& sum)
{
    if (i >= ROWS)
        return;

    if (MatchesCriteria(R[i][j], i, j))
    {
        count++;
        sum += R[i][j];
        R[i][j] = 0;
    }

    if (j < COLS - 1)
        Calc(R, i, j + 1, count, sum);
    else
        Calc(R, i + 1, 0, count, sum);
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

// Рекурсивний обмін двох рядків
void Change(int R[][COLS], const int row1,
    const int row2, const int j)
{
    if (j >= COLS)
        return;

    int temp = R[row1][j];
    R[row1][j] = R[row2][j];
    R[row2][j] = temp;

    Change(R, row1, row2, j + 1);
}

// Рекурсивний прохід сортування
void SortPass(int R[][COLS], const int i,
    const int last)
{
    if (i >= last)
        return;

    if (NeedSwap(R, i))
        Change(R, i, i + 1, 0);

    SortPass(R, i + 1, last);
}

// Рекурсивне сортування рядків
void Sort(int R[][COLS], const int pass)
{
    if (pass >= ROWS - 1)
        return;

    SortPass(R, 0, ROWS - 1 - pass);

    Sort(R, pass + 1);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int Low = 4;
    const int High = 51;

    int R[ROWS][COLS];
    int R1[ROWS][COLS];
    int R2[ROWS][COLS];

    Create(R, 0, 0, Low, High);

    Copy(R, R1, 0, 0);
    Copy(R, R2, 0, 0);

    cout << "Original matrix:" << endl;
    Print(R, 0, 0);

    // Завдання 1
    int count = 0;
    int sum = 0;

    Calc(R1, 0, 0, count, sum);

    cout << "Task 1:" << endl;
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    cout << "Modified matrix:" << endl;
    Print(R1, 0, 0);

    // Завдання 2
    Sort(R2, 0);

    cout << "Task 2:" << endl;
    cout << "Sorted matrix:" << endl;
    Print(R2, 0, 0);

    return 0;
}
