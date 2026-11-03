
// Lab-07.2-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів
// Варіант 31 — рекурсивний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 10;

// Рекурсивне створення матриці
void Create(int a[][MAX_SIZE], const int n,
    const int Low, const int High,
    const int i, const int j)
{
    if (i >= n)
        return;

    a[i][j] = Low + rand() % (High - Low + 1);

    if (j < n - 1)
        Create(a, n, Low, High, i, j + 1);
    else
        Create(a, n, Low, High, i + 1, 0);
}

// Рекурсивне виведення матриці
void Print(const int a[][MAX_SIZE], const int n,
    const int i, const int j)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << a[i][j];

    if (j < n - 1)
    {
        Print(a, n, i, j + 1);
    }
    else
    {
        cout << endl;
        Print(a, n, i + 1, 0);
    }
}

// Пошук найбільшого елемента діагоналі
int FindMaxDiagonal(const int a[][MAX_SIZE],
    const int n, const int i,
    const int maxIndex)
{
    if (i >= n)
        return maxIndex;

    int index = maxIndex;

    if (a[i][i] > a[index][index])
        index = i;

    return FindMaxDiagonal(a, n, i + 1, index);
}

// Рекурсивне сортування діагоналі
void SortDiagonal(int a[][MAX_SIZE],
    const int n, const int i)
{
    if (i >= n - 1)
        return;

    int maxIndex = FindMaxDiagonal(a, n, i + 1, i);

    int temp = a[i][i];
    a[i][i] = a[maxIndex][maxIndex];
    a[maxIndex][maxIndex] = temp;

    SortDiagonal(a, n, i + 1);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;

    cout << "Enter n (1-10): ";
    cin >> n;

    if (!cin || n < 1 || n > MAX_SIZE)
    {
        cout << "Invalid n!" << endl;
        return 1;
    }

    const int Low = -20;
    const int High = 20;

    int a[MAX_SIZE][MAX_SIZE];

    Create(a, n, Low, High, 0, 0);

    cout << "Original matrix:" << endl;
    Print(a, n, 0, 0);

    SortDiagonal(a, n, 0);

    cout << "Sorted matrix:" << endl;
    Print(a, n, 0, 0);

    return 0;
}
