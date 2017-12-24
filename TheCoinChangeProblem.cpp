#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int MAX_SUM = 255;
const int MAX_NUM = 55;

int sum, num;
int coinTable[MAX_NUM];
long long int memo[MAX_SUM];

long long solve(){
    for(int i = 0; i < num; i++){
        for(int j = coinTable[i]; j <= sum; j++){
            memo[j] += memo[j - coinTable[i]];
        }
    }
    return memo[sum];
}

int main(int argc, char const *argv[]) {
    std::cin >> sum;
    std::cin >> num;
    for(int i = 0; i < num; i++){
        std::cin >> coinTable[i];
    }
    for(int i = 0; i < MAX_SUM; i++){
        memo[i] = 0;
    }
    memo[0] = 1;
    std::sort(coinTable,  coinTable+num);
    std::cout << solve() << '\n';
    return 0;
}
