#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int g;  //test case
int scoreTable[100010];  //primeNumberTable

#define f(i, t, n) for(int i = t; i < n; i++)

void find_prime(int start, int end){
    if(end == 1){
        return;
    }
    f(i, start, end+1){
        f(j, 1, i){
            if(i % j == 0 && j != 1){
                scoreTable[i] = scoreTable[i-1];
                break;
            }
            if(j == i-1){
                scoreTable[i] = scoreTable[i-1]+1;
            }
        }
    }
    return;
}

int main(){
    int g;
    std::cin >> g;
    int maxNumber = 1;
    f(i, 0, 100010){
        scoreTable[i] = 0;
    }
    f(i, 0, g){
        int n;
        std::cin >> n;
        if(maxNumber < n){
            find_prime(maxNumber+1, n);
            maxNumber = n;
        }her
        if(scoreTable[n] % 2 == 0){
            std::cout << "Bob" << '\n';
        } else {
            std::cout << "Alice" << '\n';
        }
    }
    return 0;
}
