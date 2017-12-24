#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

#define f(i, t, n) for(long long i = t; i < n; i++)

struct node {
    long long num;
    long long order;
};

long long g;  //chooose the number of game
std::vector<node> v;

//return loser player
long long  gamePlay(){
    long long  score = 1;
    long long max = v[0].num;
    f(i, 1, v.size()){
        if(v[i].num > max){
            score++;
            max = v[i].num;
        }
    }
    return score;
}

void solve(){
    int n;
    std::cin >> n;         //input  number of integers
    f(i, 0, n){         //input data
        node N;
        std::cin >> N.num;
        N.order = i;
        v.push_back(N);
    }
    if(gamePlay() % 2 == 0) {     //play
        std::cout << "ANDY" << '\n';
    } else {
        std::cout << "BOB" << '\n';
    }
}

int main(int argc, char const *argv[]) {
    std::cin >> g;
    while(g--){
        solve();
        v.clear();
    }
    return 0;
}
