// Лабораторная работа №8 Задание 3 Вариант 9
//
// Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
// Найти строку, в которой меньше всего четных чисел, и заменить все элементы этой строки их квадратами.
// 
// Переделайте задания 2 и 3 из лабораторной работы №4 своего варианта, разместив массивы в динамической памяти. 
// Размеры массивов задавайте согласно введенным данным.

#include <iostream>

void readArray(int** array, int& n, int& m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> array[i][j];
        }
    }
}

void printArray(int** array, int& n, int& m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << array[i][m-1] << std::endl;
    }
}

void counting(int** array, int& n, int& m, int& line_i, int& line_count_min) {
    for (int i = 0; i < n; i++) {
        int line_count = 0;
        for (int j = 0; j < m; j++) {
            if (array[i][j] % 2 == 0) line_count++;
        }
        if (line_count < line_count_min) {
            line_count_min = line_count;
            line_i = i;
        }
    }
}

void changeArray(int** array, int lineNumber, int& m) {
    for (int j = 0; j < m; j++) {
        array[lineNumber][j] *= array[lineNumber][j];
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }

    readArray(array,n,m);

    /* Пример массива для ввода
    4 9
    1 1 2 3 4 5 55 33 2
    4 8 2 3 1 4 6 32 15 
    1 1 2 2 3 4 5 66 7 
    2 1 3 4 5 5 55 3 1
    */

    int line_i = -1; // номер строки с наименьшим количеством чётных чисел
    int line_count_min = n;

    counting(array, n, m, line_i, line_count_min);

    printArray(array, n, m);
    std::cout << std::endl;

    changeArray(array, line_i, m);
    printArray(array, n, m);

    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}