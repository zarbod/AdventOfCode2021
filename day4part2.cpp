#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool checkBingo(vector<vector<int>> board);
int calcScore(vector<vector<int>> board, int last);

int main() {
    ifstream inputFile; inputFile.open(R"(input4.txt)");

    string draws;

    inputFile >> draws;

    stringstream s_stream(draws);

    vector<int> drawNums;

    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        stringstream number(substr);
        int x = 0;
        number >> x;
        drawNums.push_back(x);
    }

    string line;

    vector<vector<vector<int>>> boards;

    while(inputFile) {
        vector<vector<int>> board;
        for(int i = 0; i < 5; i++){
            vector<int> row;
            for(int j = 0; j < 5; j++) {
                inputFile >> line;
                stringstream number(line);
                int x = 0;
                number >> x;
                row.push_back(x);
            }
            board.push_back(row);
        }
        boards.push_back(board);
    }

    boards.pop_back();

    // checks for board that reaches bingo firs
    int last = 0;
    vector<vector<int>> winBoard;
    for(int n = 0; n < drawNums.size(); n++){
        int check = drawNums[n];

        for(int i = 0; i < boards.size(); i++){
            for(int j = 0; j < 5; j++) {
                for(int k = 0; k < 5; k++) {
                    if(boards[i][j][k] == check)
                        boards[i][j][k] *= 100;
                }
            }
        }

        if(n > 3){
            for(int i = 0; i < boards.size(); i++){
                if(boards.size() == 0)
                    goto SCORE;
                if(checkBingo(boards[i])){
                    last = drawNums[n];
                    winBoard = boards[i];
                    boards.erase(boards.begin() + i);
                    i--;
                }
            }
        }
    }
    SCORE:
    cout << calcScore(winBoard, last);
}

int calcScore(vector<vector<int>> board, int last){
    int sum = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            if(board[i][j] % 100 != 0)
                sum += board[i][j];
        }
    return last * sum;
}

bool checkBingo(vector<vector<int>> board) {
    //horizontal checks
    for(int i = 0; i < 5; i++){
        if(board[i][0] % 100 == 0 && board[i][1] % 100 == 0 && board[i][2] % 100 == 0 && board[i][3] % 100 == 0 &&
           board[i][4] % 100 == 0)
            return true;
    }

    //vertical checks
    for(int i = 0; i < 5; i++){
        if(board[0][i] % 100 == 0 && board[1][i] % 100 == 0 && board[2][i] % 100 == 0 && board[3][i] % 100 == 0 &&
           board[4][i] % 100 == 0)
            return true;
    }

    return false;
}
