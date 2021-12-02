#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile; inputFile.open("input1.txt");

    vector<int> values;
    string lineString;
    while(inputFile) {
        inputFile >> lineString;
        stringstream number(lineString);
        int x = 0;
        number >> x;
        values.push_back(x);
    }

    values.pop_back();


    int i = 1;

    int sum1, sum2;
    int count = 0;
    sum1 = values.at(0) + values.at(1) + values.at(2);

    while(k < values.size()) {
        sum2 = values.at(i) + values.at(i+1) + values.at(i+2);
        if(sum2 > sum1)
            count++;
        i++;
        sum1 = sum2;
    }

    cout << count;
}


