//
// Created by pantr on 18/09/2022.
//

#ifndef ACTIVITY_2_2_HASHSTRING_H
#define ACTIVITY_2_2_HASHSTRING_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class HashString{
private:
    vector<vector<string>> extractFile(const string&, int );
public:
    string generateHashString(const string&, int );
};

string HashString::generateHashString(const std::string& fileName, int size) {
    string hexString;
    vector<vector<string>> hashMatrix;

    hashMatrix = extractFile(fileName, size);

    for (int i = 0; i < hashMatrix.size(); ++i) {
        for (int j = 0; j < hashMatrix[i].size(); ++j) {
            cout << "{ " << hashMatrix[i][j] << " }" << endl;
        }
    }

    return hexString;
}

vector<vector<string>> HashString::extractFile(const string& fileName, int size) {
    int tempLimit = 0;
    string tempString, text;
    vector<string> temp;
    vector<vector<string>> fileMatrix;

    ifstream myFile(fileName);

    while (getline (myFile, tempString)) {
        text += tempString;
    }

    myFile.close();
    tempString.clear();

    for (int i = 0; i <= text.size() - 1; ++i) {
        if (tempLimit >= text.size()){
            tempLimit = text.size() - 1;
            for (int j = i; j < tempLimit; ++j) {
                tempString += text[j];
            }
            temp.push_back(tempString);
        }else{
            tempLimit = i + size;
            for (int j = i; j < tempLimit; ++j) {
                tempString += text[j];
            }
            temp.push_back(tempString);
        }
        fileMatrix.push_back(temp);
        temp.clear();
        tempString.clear();
        i = tempLimit;
    }

    return fileMatrix;
}

#endif //ACTIVITY_2_2_HASHSTRING_H
