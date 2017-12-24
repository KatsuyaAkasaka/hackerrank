#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

const int MAX_N = 10;

struct Vec {
    int r;
    int c;
};

int row, column;
int table[MAX_N][MAX_N];
std::queue <Vec> q;

void queueClear(){
    while(!q.empty()){
        q.pop();
    }
}

void pushCells(int r, int c){
    Vec v;
    v.r = r; v.c = c;
    q.push(v);
}

void tableChange(int r, int c){
    table[r][c] = 0;
}

int searchAroundPos(int r, int c){
    int score = 0;
    while(!q.empty()){
        int x = q.front().r;
        int y = q.front().c;
        for(int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++) {
                if(table[x+i][y+j] && x+i >= 0 && x+i < row && y+j >= 0 && y+j < column){
                    pushCells(x+i, y+j);
                    tableChange(x+i, y+j);
                }
            }
        }
        q.pop();
        score++;
    }
    return score;
}

int searchStartPos(){
    int max = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(table[i][j] == 1){
                pushCells(i, j);
                tableChange(i, j);
                int sum = searchAroundPos(i, j);
                if (max < sum){
                    max = sum;
                }
                queueClear();
            }
        }
    }
    return max;
}


int main(int argc, char const *argv[]) {
    std::cin >> row >> column;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            std::cin >> table[i][j];
        }
    }

    std::cout << searchStartPos() << '\n';

    return 0;
}
