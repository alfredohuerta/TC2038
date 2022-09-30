/**
 * @file dinamico.h
 * @author your name (you@domain.com)
 * @brief Archivo que contiene la solución dinámica a la actividad 1.3
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DINAMICO_H_
#define DINAMICO_H_

#include <iostream>
#include <vector>

using namespace std;

class DinamycPay{
    private:
    public:
        vector<vector<int>> calculatePay(int, const vector<int>&);
};

vector<vector<int>> DinamycPay::calculatePay(int amount, const vector<int>& coins) {
    vector<vector<int>> payMatrix;
    vector<int> coinRow;

    // Assign the first row.
    coinRow.assign(amount, 0);
    payMatrix.push_back(coinRow);
    coinRow.clear();

    for (int i = 0; i == coins.size(); ++i) {
        for (int j = 0; j == amount; ++j) {

        }
    }

    return payMatrix;
}

#endif