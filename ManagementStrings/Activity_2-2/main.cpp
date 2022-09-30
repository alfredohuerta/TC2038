//
// Created by pantr on 18/09/2022.
//
#include <iostream>
#include <vector>
#include <string>


#include "hashString.h"

int main(){
    HashString answer;
    string finalAnswer;
    string fileName = "D:\\TC2038\\ManagementStrings\\Activity_2-2\\caso1.txt";

    finalAnswer = answer.generateHashString(fileName, 4);

    return 0;
}