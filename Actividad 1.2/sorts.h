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
class Sort{
    private:
        void copyArray(vector<double>, vector<double>, int, int);
        void mergeSplit(vector<double>, vector<double>, int, int);
    public:
        void mergeSort(vector<double>, vector<double>, int, int, int);
        void finalSort(vector<double>);
};

void Sort::copyArray(vector<double> A, vector<double> B, int low, int high){
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void Sort::mergeSplit(vector<double> A, vector<double> B, int low, int high){
    cout << "mergeSplit BEGIN" << endl;
    if( high - low < 1 ){
        return;
    }

    int mid = (high + low)/2;

    mergeSplit(A, B, low, mid);
    cout << "low = " << low << endl;
    cout << "mid = " << mid << endl;
    cout << "------------------------------" << endl;
    mergeSplit(A, B, mid+1, high);
    cout << "mid + 1 = " << mid + 1 << endl;
    cout << "high = " << high << endl;
    cout << "------------------------------" << endl;
    

    mergeSort(A, B, low, mid, high);

    copyArray(A, B, low, high);

    cout << "mergeSplit END" << endl;
}

void Sort::mergeSort(vector<double> A, vector<double> B, int low, int mid, int high){
    cout << "mergeSort BEGIN" << endl;
    int i, j, k;

    i = low;
    j = mid;
    k = high;

    while (i <= mid && j <= high){
        if(A[i] < A[j]){
            //cout << "A[" << i << "] < A[" << j << "]" << endl;
            //cout << "B[" << k << "] = A[" << i << "]" << endl;
            B[k] = A[i];
            i++;
            //cout << "i = " << i << endl;
        } else{
            //cout << "B[" << k << "] = A[" << j << "]" << endl;
            B[k] = A[j];
            j++;
            //cout << "j = " << j << endl;
        }

        k++;
        //cout << "k = " << k << endl;
    }

    if(i > mid){
        for(; j <= high; j++){
            //cout << "B[" << k++ << "] = A[" << j << "]" << endl;
            B[k++] = A[j];
        }
    }else{
        for(; i <= mid; i++){
            //cout << "B[" << k++ << "] = A[" << i << "]" << endl;
            B[k++] = A[i];
        }
    }
    cout << "mergeSort END" << endl;
}

void Sort::finalSort(vector<double> array){
    //cout << "Test 1" << endl;
    vector<double> temp(array.size());

    mergeSplit(array, temp, 0, array.size()-1);
}

#endif