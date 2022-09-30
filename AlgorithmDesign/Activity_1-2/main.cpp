//
// Created by pantr on 13/09/2022.
//
#include <iostream>
#include <vector>

#include "sorts.h"

using namespace std;

int main(){
    vector<double> array = {2, 1.2, 3, 5.1, 2.4, 5, 6, 7, 10, 3.2};

    Sorts sorts;

    cout << "Arreglo inicial: {";
    for (int i = 0; i < array.size(); ++i) {
        cout << " " << array[i] << " ";
    }
    cout << "}" << endl;

    sorts.mergeSort(array);

    cout << "Arreglo inicial: {";
    for (int i = 0; i < array.size(); ++i) {
        cout << " " << array[i] << " ";
    }
    cout << "}" << endl;

    return 0;
}