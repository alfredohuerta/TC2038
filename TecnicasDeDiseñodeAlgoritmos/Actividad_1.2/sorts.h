/**
 * @file sorts.h
 * @author Erick Alfredo García Huerta - A01708119
 * @brief Archivo que contiene el mergesort
 * @version 0.1
 * @date 2022-08-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

using namespace std;

/**
 * @brief Se crea la clase que va a almacenar los métodos necesarios para realizar el sort.
 *
 */
class Sort
{
private:
    void copyArray(vector<double>, vector<double>, int, int);
    void mergeSplit(vector<double>, vector<double>, int, int);

public:
    void mergeSort(vector<double>, vector<double>, int, int, int);
    void finalSort(vector<double>);
};

void Sort::copyArray(vector<double> A, vector<double> B, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void Sort::mergeSplit(vector<double> A, vector<double> B, int low, int high)
{
    if (high - low <= 1)
    {
        return;
    }

    int mid = (high + low) / 2;

    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);

    mergeSort(A, B, low, mid, high);

    copyArray(A, B, low, high);
}

void Sort::mergeSort(vector<double> A, vector<double> B, int low, int mid, int high)
{
    int i, j, k;

    i = low;
    j = mid;
    k = high;

    while (i < mid && j < high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
    }

    if (i > mid)
    {
        for (; j <= high; j++)
        {
            B[k++] = A[j];
        }
    }
    else
    {
        for (; i <= mid; i++)
        {
            B[k++] = A[i];
        }
    }
}

void Sort::finalSort(vector<double> array)
{
    vector<double> temp(array.size());

    mergeSplit(array, temp, 0, array.size() - 1);
}

#endif