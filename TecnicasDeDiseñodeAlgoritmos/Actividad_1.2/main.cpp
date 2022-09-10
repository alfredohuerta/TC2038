/**
 * @file A12_MergeSort_Equipo_02.cpp
 * @author Erick Alfredo García Huerta - A01708119
 * @brief Utilizando la técnica de programación de "divide y vencerás", realiza en C++ un programa que implemente el
 * algoritmo de MergeSort.
 * @version 0.1
 * @date 2022-08-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include "sorts.h"

using namespace std;

int main()
{

    vector<double> test = {0, 1, 2, 3, 5, 6, 7, 9, 8, 10, 4};
    vector<double> final;

    Sort sorts;

    cout << "Test size = " << test.size() << endl;
    cout << "Prueba: (";
    for (int i = 0; i < test.size(); i++)
    {
        cout << "Test[" << i << "] = " << test[i] << " ";
    }
    cout << ")" << endl;

    sorts.finalSort(test);

    cout << endl
         << "Final: (";
    for (int i = 0; i < test.size(); i++)
    {
        cout << " " << test[i];
    }
    cout << ")" << endl;

    return 0;
}