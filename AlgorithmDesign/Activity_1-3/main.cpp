/**
 * @file main.cpp
 * @author Erick Alfredo García Huerta - A01708119
 * @brief Archivo principal de la solución a la actividad 1.3
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include "avaro.h"
#include "dinamico.h"

using namespace std;

int main(){
    int price = 10, quantity;
    /*cout << "Ingrese el price del producto que quiere pagar:   $";
    cin >> price;
    cout << endl << "Ingrese la quantity que usara para pagar:     $";
    cin >> quantity;

    // Parte con el algoritmo avaro.
    Pago_avaro pago;
    vector<int>test = pago.transaccion(price, quantity);

    cout << endl << "Este es su cambio: \n" << endl;
    cout << test[0] << " billte(s) de $1000." << endl;
    cout << test[1] << " billte(s) de $500." << endl;
    cout << test[2] << " billte(s) de $200." << endl;
    cout << test[3] << " billte(s) de $100." << endl;
    cout << test[4] << " billte(s) de $50." << endl;
    cout << test[5] << " billte(s) de $20." << endl;
    cout << test[6] << " moneda(s) de $10." << endl;
    cout << test[7] << " moneda(s) de $5." << endl;
    cout << test[8] << " moneda(s) de $2." << endl;
    cout << test[9] << " moneda(s) de $1." << endl;*/

    // Parte con el algoritmo dinamico
    vector<int> money = {1, 2, 3};
    vector<vector<int>> resultMatrix;

    DinamycPay dinamyc;

    resultMatrix = dinamyc.calculatePay(price, money);

    cout << "{";
    for (int i = 0; i < resultMatrix.size(); ++i) {
        cout << "\n{";
        for (int j = 0; j < resultMatrix[i].size(); ++j) {
            cout << " " << resultMatrix[i][j] << " ";
        }
        cout << "}";
    }
    cout << "\n}";
    return 0;
}