//
// Created by aaroh on 12/2/2021.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile; inputFile.open("input1.txt");
    string lineString;
    int i = 0;
    int lastNum = 0;
    int sum = 0;
    if ( inputFile.is_open() ) {
        while(inputFile){
            inputFile >> lineString;
            stringstream number(lineString);
            int x = 0;
            number >> x;
            if(i == 0){
                i++;
                lastNum = x;
            }
            else {
                if (lastNum < x)
                    sum++;
                lastNum = x;
            }
        }
        cout << sum;
    }
