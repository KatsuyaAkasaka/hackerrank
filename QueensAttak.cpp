#include <iostream>

#define rep(i, n) for(long long i =0 ; i < n; i++)

const long long max_array = 100010;
int obstacle[2][max_array];
int n;
int score = 0;

bool hit(int x, int y){
    rep(i, n){
        if(obstacle[0][i] == x && obstacle[1][i] == y){
            return true;
        }
    }
    return false;
}

void leftdown(int x, int y){
    x--;
    y--;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
//        std::cout << x << y << '\n';
        x--;
        y--;
    }
    return;
}

void left(int x, int y){
    x--;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        x--;
    }
    return;
}

void leftup(int x, int y){
    x--;
    y++;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        x--;
        y++;
    }
    return;
}
void up(int x, int y){
    y++;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        y++;
    }
    return;
}

void rightup(int x, int y){
    x++;
    y++;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        x++;
        y++;
    }
    return;
}

void right(int x, int y){
    x++;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        x++;
    }
    return;
}

void rightdown(int x, int y){
    x++;
    y--;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        x++;
        y--;
    }
    return;
}

void down(int x, int y){
    y--;
    while (x > 0 && y > 0 && x <= n && y <= n) {
        if(hit(x, y)){
            break;
        }
        score++;
    //    std::cout << x << y << '\n';
        y--;
    }
    return;
}


void makeMarking(int x, int y){
    leftdown(x, y);
    left(x, y);
    leftup(x, y);
    up(x, y);
    rightup(x, y);
    right(x, y);
    rightdown(x, y);
    down(x, y);
    return;
}

int main(int argc, char const *argv[]) {
    int k;
    int posx, posy;
    std::cin >> n >> k;
    std::cin >> posx >> posy;
    rep(i, max_array) {
        obstacle[0][i] = 0;
        obstacle[1][i] = 0;
    }
    rep(i, k) {
        std::cin >> obstacle[0][i] >> obstacle[1][i];
    }
    makeMarking(posx, posy);

    std::cout << score << '\n';
    return 0;
}
