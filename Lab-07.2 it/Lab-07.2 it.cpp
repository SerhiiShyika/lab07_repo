
// Lab-07.2-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів
// Варіант 31 — ітераційний метод

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 10;

// Створення матриці
void Create(int a[][MAX_SIZE], const int n,
    const int Low, const int High)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Виведення матриці
void Print(const int a[][MAX_SIZE], const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Сортування головної діагоналі за спаданням
void SortDiagonal(int a[][MAX_SIZE], const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][i] < a[j][j])
            {
                int temp = a[i][i];
                a[i][i] = a[j][j];
                a[j][j] = temp;
            }
        }
    }
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

    Create(a, n, Low, High);

    cout << "Original matrix:" << endl;
    Print(a, n);

    SortDiagonal(a, n);

    cout << "Sorted matrix:" << endl;
    Print(a, n);

    return 0;
}
