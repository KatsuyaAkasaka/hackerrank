#include <iostream>

#define rep(i, n) for(int i = 0; i < n; i++)
const int maxNum = 10010;
int occurs[2][maxNum];

int main(int argc, char const *argv[]) {
    rep(i, maxNum){
        occurs[0][i] = 0;
        occurs[1][i] = 0;
    }
    int n, m, x;
    std::cin >> n;
    rep(i, n) {
        std::cin >> x;
        occurs[0][x]++;
    }
    std::cin >> m;
    rep(i, m) {
        std::cin >> x;
        occurs[1][x]++;
    }

    rep(i, maxNum) {
        if(occurs[0][i] > 1 && occurs[1][i] > 1 && (occurs[0][i] != occurs[1][i])){
            std::cout << i << " ";
        }
    }
    std::cout << '\n';

    return 0;
}
