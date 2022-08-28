/**
 * @file avaro.h
 * @author Erick Alfredo García Huerta - A01708119
 * @brief Este archivo contiene las funciones para la resolución de la actividad 1.3
 *        Para su resolución se decidió dividir el problema en dos funciones, uno que analice las entradas y regrese el
 *        cambio pertinente y otro que lleve a cabo el cálculo de la diferencia y active la función que contien el 
 *        analizador.
 *        El analizador es un algoritmo ávaro debido a que recorre el arreglo de monedas buscando la primera coincidencia
 *        con la finalidad de juntar coincidencias rápidas que aceleren el proceso, reduciendo el cambio que hay que dar
 *        con cada paso exitoso del ciclo.
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 **/

#ifndef AVARO_H_
#define AVARO_H_

#include <vector>

using namespace std;

//Variable global que contiene las referencias de los valores de los billetes y monedas.
vector<int> dinero = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

//Vector que almacenará las cantidades de monedas o billetes de cambio.
vector<int> cambio = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Pago{
  public:
    vector<int> transaccion(int, int);
  private:
    vector<int> calc_cambio(int);
};

/**
 * @brief Función auxiliar que resuelve el subproblema de calcular el cambio a entregar. La función recibe la diferencia
 * entre el pago y el precio del producto y mediante un ciclo  recursivo compara la diferencia con los billetes disponibles
 * subiendo el contador de cuántos billetes o monedas de cada denominación tienen que entregarse.
 * 
 * @param diferencia 
 * @return cambio
 */
vector<int> Pago::calc_cambio(int diferencia){
    if(diferencia == 0){
        return cambio;
    }else{
        if(diferencia > dinero[0]){ //$1000
            cambio[0]++;
            calc_cambio(diferencia - dinero[0]);

        }else if(diferencia > dinero[1]){//$500
            cambio[1]++;
            calc_cambio(diferencia - dinero[1]);

        }else if(diferencia > dinero[2]){//$200
            cambio[2]++;
            calc_cambio(diferencia - dinero[2]);

        }else if(diferencia > dinero[3]){//$100
            cambio[3]++;
            calc_cambio(diferencia - dinero[3]);

        }else if(diferencia > dinero[4]){//$50
            cambio[4]++;
            calc_cambio(diferencia - dinero[4]);

        }else if(diferencia > dinero[5]){//$20
            cambio[5]++;
            calc_cambio(diferencia - dinero[5]);

        }else if(diferencia > dinero[6]){//$10
            cambio[6]++;
            calc_cambio(diferencia - dinero[6]);

        }else if(diferencia > dinero[7]){//$5
            cambio[7]++;
            calc_cambio(diferencia - dinero[7]);

        }else if(diferencia > dinero[8]){//$2
            cambio[8]++;
            calc_cambio(diferencia - dinero[8]);

        }else if(diferencia > dinero[9]){//$1
            cambio[9]++;
            calc_cambio(diferencia - dinero[9]);
        }
    }
    
    return cambio;
}

/**
 * @brief Función principal que recibe tanto el precio del producto como el pago dado, genera la diferencia y llama a la
 * función que genera el cambio.
 * 
 * @param precio
 * @param pago 
 * @return vector<int> 
 */
vector<int> Pago::transaccion(int precio, int pago){
    int dif = pago - precio;

    vector<int> temp = calc_cambio(dif);

    return temp;
}

#endif