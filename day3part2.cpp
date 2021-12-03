#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int toBinary(string bin);

int main() {
    ifstream inputFile; inputFile.open("C:\\Users\\aaroh\\CLionProjects\\untitled\\input3.txt");

    vector<string> values;
    string lineString;
    while(inputFile) {
        inputFile >> lineString;
        values.push_back(lineString);
    }

    values.pop_back();

    int zeroCount = 0;
    int oneCount = 0;

    vector<string> valCopy = values;

    for (int i = 0; i < 12; i++){
        if(values.size() < 2)
            break;
        for(string j: values){
            if(j.substr(i, 1) == "0")
            {
                zeroCount++;
            }
            else
                oneCount++;
        }

        if(zeroCount > oneCount)
        {
            for (int k = 0; k < values.size(); k++){
                if(values.at(k).substr(i, 1) == "1"){
                    values.erase(values.begin() + k);
                    k--;
                }
            }
        }
        else {
            for (int k = 0; k < values.size(); k++){
                if(values.at(k).substr(i, 1) == "0"){
                    values.erase(values.begin() + k);
                    k--;
                }
            }
        }

        zeroCount = 0;
        oneCount = 0;
    }
    for (int i = 0; i < 12; i++){
        if(valCopy.size() < 2)
            break;
        for(string j: valCopy){
            if(j.substr(i, 1) == "0")
            {
                zeroCount++;
            }
            else
                oneCount++;
        }

        if(zeroCount > oneCount)
        {
            for (int k = 0; k < valCopy.size(); k++){
                if(valCopy.at(k).substr(i, 1) == "0"){
                    valCopy.erase(valCopy.begin() + k);
                    k--;
                }
            }
        }
        else {
            for (int k = 0; k < valCopy.size(); k++){
                if(valCopy.at(k).substr(i, 1) == "1"){
                    valCopy.erase(valCopy.begin() + k);
                    k--;
                }
            }
        }

        zeroCount = 0;
        oneCount = 0;
    }

    string ox = values[0];
    string co = valCopy[0];

    int oxy = toBinary(ox);
    int co2 = toBinary(co);

    cout << oxy * co2;
}

int toBinary(string bin) {
    int dec = 0;
    int base = 1;

    for(int i = 0; i < bin.size(); i++)
    {
        if(bin.substr(bin.size()-i-1, 1) == "1"){
            dec += base;
        }
        base *= 2;
    }

    return dec;
}