//
// Created by Erick Alfredo García Huerta
//

#ifndef ACTIVITY_1_2_SORTS_H
#define ACTIVITY_1_2_SORTS_H

#include <vector>
#include <iostream>
#include <vector>

using namespace std;

class Sorts{
private:
    void copyArray(vector<double>, vector<double>, int, int);
    void meregeArray(vector<double>, vector<double>, int, int, int);
    void mergeSplit(vector<double>, vector<double>, int , int );
public:
    void mergeSort(const vector<double>&);
};

void Sorts::mergeSplit(vector<double> A, vector<double> B, int low, int high) {
    if(high - low < 1){
        return;
    }

    int mid= (high + low)/2;

    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid+1, high);

    meregeArray(A, B, low, mid, high);
}

void Sorts::meregeArray(vector<double> A, vector<double> B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }

    copyArray(A, B, low, high);
}

void Sorts::copyArray(vector<double> A, vector<double> B, int low, int high) {
    for(int i= low; i <= high; i++){
        A[i]= B[i];
    }
}

void Sorts::mergeSort(const vector<double>& array) {
    vector<double> temp(array.size());
    mergeSplit(array, temp, 0, array.size()-1);
}

#endif //ACTIVITY_1_2_SORTS_H
