#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MAX_N = 25;
int ans[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N];
int length;
int prevDepth;

struct Vec {
    int x;
    int y;
    int depth;
};

std::queue <Vec> q;
Vec v;

void init(){
    while(!q.empty()){
        q.pop();
    }
    for(int i = 0; i < length; i++){
        for (int j = 0; j < length; j++) {
            isVisited[i][j] = false;
        }
    }
    v.x = 0;
    v.y = 0;
    v.depth = 0;
    q.push(v);
}

void push_queue(int nextPosX, int nextPosY){
    if(0 <= nextPosX && nextPosX < length && 0 <= nextPosY && nextPosY < length){
        if(isVisited[nextPosX][nextPosY]){
            return;
        }
        v.x = nextPosX;
        v.y = nextPosY;
        v.depth = q.front().depth + 1;
        isVisited[nextPosX][nextPosY] = true;
        q.push(v);
    }
    return;
}

int bfs(int moveX, int moveY){
    int posX = q.front().x;
    int posY = q.front().y;
    isVisited[posX][posY] = true;

    if(posX == length-1 && posY == length-1){
        return 0;
    }

    push_queue(posX + moveX, posY + moveY);
    push_queue(posX + moveX, posY - moveY);
    push_queue(posX - moveX, posY + moveY);
    push_queue(posX - moveX, posY - moveY);
    push_queue(posX + moveY, posY + moveX);
    push_queue(posX + moveY, posY - moveX);
    push_queue(posX - moveY, posY + moveX);
    push_queue(posX - moveY, posY - moveX);

    prevDepth = q.front().depth;
    q.pop();
    if(q.empty()){
        return -700;
    }
    if(q.front().depth != prevDepth){
        return bfs(moveX, moveY) + 1;
    } else {
        return bfs(moveX, moveY);
    }
}



int main(int argc, char const *argv[]) {
    std::cin >> length;

    for(int i = 0; i < length; i++){
        for (int j = 0; j < length; j++) {
            ans [i][j] = 0;
            isVisited[i][j] = false;
        }
    }

    for(int i = 1; i < length; i++){
        for(int j = i; j < length; j++){
            init();
            int score = bfs(i, j);
            if(score < 0){
                score = -1;
            }
            ans[i][j] = score;
            ans[j][i] = score;
        }
    }

    for(int i = 1; i < length; i++){
        for (int j = 1; j < length; j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
