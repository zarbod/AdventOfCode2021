#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
    std::ifstream inputFile; inputFile.open("input2.txt");
    int x = 0;
    int y = 0;
    int aim = 0;
    std::string lineString;
    while(inputFile){
        inputFile >> lineString;
        std::string dir = lineString.substr(0, lineString.size());
        int incr = 0;
        inputFile >> lineString;
        std::stringstream number(lineString);
        number >> incr;
        if (dir == "forward") {
            x += incr;
            y += (incr * aim);
        }
        else if (dir == "down") {
            aim += incr;
        }
        else if (dir == "up"){
            aim -= incr;
        }
    }
    std::cout << x*y << std::endl;
}