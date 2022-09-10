//
// Created by pantr on 06/09/2022.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string chain;

    cout << "Write the string: ";
    cin >> chain;

    vector<string> suffixes; // Here the suffixes will be saved.

    for (int i = chain.size() - 1; i >= 0 ; i--) {
        suffixes.push_back(chain.substr(i, chain.size())); // extract the substrings from the original string
    }                                                              // value.

    sort(suffixes.begin(), suffixes.end());

    for (int i = 0; i < suffixes.size(); ++i) {
        cout << i << " .- " << suffixes[i] << endl;
    }

    return 0;
};