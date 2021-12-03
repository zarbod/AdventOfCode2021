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
    string epsilon = "";
    string gamma = "";

    for (int i = 0; i < 12; i++){
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
            gamma += "0";
            epsilon += "1";
        }
        else {
            gamma += "1";
            epsilon += "0";
        }

        zeroCount = 0;
        oneCount = 0;
    }

    int decEps = toBinary(epsilon);
    int decGam = toBinary(gamma);

   cout << decEps * decGam << endl;

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


