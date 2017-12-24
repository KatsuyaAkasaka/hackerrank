#include <math.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>

#define f(i, t, n) for(int i = t; i < n; i++)
#define MAX_N 100
#define MAX_M 100
#define MAX_K 10000

struct Pos {
    int line, row;
};

int T;      //test case
int N, M;   //matrix(N, M)
int K;      //times that he guess what times she waves wand
int stage[MAX_N][MAX_M];  //the map they lose their way
                            //if -1 then tree
                            //if 0 then can pass
                            //if 1 then start
                            //if 2 then goal
Pos now;        //they are now in this
Pos goal;      //their destination
int WaveWandCount = 0;
bool isCleared = false;     //cleared or not

//return p state
//if null then return -10
int state(Pos p){
    return stage[p.line][p.row];
}

//making stage with type integer
void input_stage(){
    std::cin >> N >> M;
    f(i, 0, N){
        std::string s;
        std::cin >> s;
        f(j, 0, M){
            if(s[j] == '.'){
                stage[i][j] = 0;
            } else if(s[j] == 'X'){
                stage[i][j] = -1;
            } else if(s[j] == 'M'){
                stage[i][j] = 1;
                now.line = i; now.row = j;
            } else if(s[j] == '*'){
                stage[i][j] = 2;
                goal.line = i; goal.row = j;
            } else {
                stage[i][j] = 0;
            }
        }
    }
}

bool findRight(Pos pos){
    Pos p;
    p.row = pos.row + 1;
    p.line = pos.line;
    if(p.row >= M){
        return false;
    }
    if(state(p) == 0 || state(p) == 1 || state(p) == 2){
        return true;
    }
    return false;
}

bool findUp(Pos pos){
    Pos p;
    p.row = pos.row;
    p.line = pos.line - 1;
    if(p.line < 0){
        return false;
    }
    if(state(p) == 0 || state(p) == 1 || state(p) == 2){
        return true;
    }
    return false;
}

bool findLeft(Pos pos){
    Pos p;
    p.row = pos.row - 1;
    p.line = pos.line;
    if(p.row < 0){
        return false;
    }
    if(state(p) == 0 || state(p) == 1 || state(p) == 2){
        return true;
    }
    return false;
}

bool findDown(Pos pos){
    Pos p;
    p.row = pos.row;
    p.line = pos.line + 1;
    if(p.line >= N){
        return false;
    }
    if(state(p) == 0 || state(p) == 1 || state(p) == 2){
        return true;
    }
    return false;
}

//if p can go to 3 ways or more then true
//else false
bool findMultiPos(Pos p){
    int truecount = 0;
    if(findRight(p)){
        truecount++;
    }
    if(findDown(p)){
        truecount++;
    }
    if(findUp(p)){
        truecount++;
    }
    if(findLeft(p)){
        truecount++;
    }
    if(truecount >= 3 || (state(p) == 1 && truecount >= 2)){
        return true;
    } else {
        return false;
    }
}

//return next pos
Pos findNextPos(Pos p, std::string s){
    if(s == "right"){
        p.row++;
    } else if(s == "up"){
        p.line--;
    } else if(s == "left"){
        p.row--;
    } else if(s == "down"){
        p.line++;
    }
    return p;
}

bool nextToPosIsGoal(Pos p){
    if(state(findNextPos(p, "right")) == 2 ||
    state(findNextPos(p, "up")) == 2 ||
    state(findNextPos(p, "left")) == 2 ||
    state(findNextPos(p, "down")) == 2){
        return true;
    }
    else {
        return false;
    }
}

//recursive
int recRouteFinding(Pos p, int direc){
    Pos nextP;          //next Pos
    int isburunch = 0;      //if this node has burunch 1
                            //else 0
    int nowDirec = 3 - direc;   //come from
                                //right 0
                                //up 1
                                //left 3
                                //down 2

    //goal
    if(state(p) == 2/* || nextToPosIsGoal(p)*/){
        //std::cout << "faksnvoaingoiae" << '\n';
        isCleared = true;
        return 0;
    }

    //std::cout <<  p.line << p.row << '\n';

    //recursive
    if(findRight(p) && !isCleared && nowDirec != 0){
        //std::cout << "aaaaaaa" << '\n';
        nextP = findNextPos(p, "right");
        WaveWandCount = recRouteFinding(nextP, 0);
    }
    if(findUp(p) && !isCleared && nowDirec != 1){
        //std::cout << "bbbbbbb" << '\n';
        nextP = findNextPos(p, "up");
        WaveWandCount = recRouteFinding(nextP, 1);
    }
    if(findLeft(p) && !isCleared && nowDirec != 3){
        //std::cout << "ccccccc" << '\n';
        nextP = findNextPos(p, "left");
        WaveWandCount = recRouteFinding(nextP, 3);
    }
    if(findDown(p) && !isCleared && nowDirec != 2){
        //std::cout << "dddddddd" << '\n';
        nextP = findNextPos(p, "down");
        WaveWandCount = recRouteFinding(nextP, 2);
    }

    //if multipos finded, add 1
    if(findMultiPos(p) && isCleared){
        //std::cout << p.line << p.row << '\n';
        isburunch = 1;
    } else {
        isburunch = 0;
    }
    return isburunch + WaveWandCount;
}

int waveWand(){
    return recRouteFinding(now, -1);
}

std::string solve(){
    //std::cout << waveWand() << '\n';
    if(waveWand() == K){
        return "Impressed";
    } else {
        return "Oops!";
    }
}

int main() {
    std::cin >> T;
    while(T--){
        isCleared = false;
        WaveWandCount = 0;
        input_stage();
        std::cin >> K;  //input guess times
        std::cout << solve() << '\n';
    }
    return 0;
}
