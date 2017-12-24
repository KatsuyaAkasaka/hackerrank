#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

#define rep(i, n) for(long long i = 0; i < n; i++)

const long long N = 100010;
bool filledData[N];

void init(){
    rep(i, N) filledData[i] = false;
    return;
}

long long find_pairs(long long n, long long k, long long m){
    long long ans = 0;
    rep(i, m-k+1){
        std::cout << "passed : " << i << '\n';
        if(i + k > N) break;
        if(filledData[i] && filledData[i + k]){
            std::cout << "called : " << i << '\n';
            ans++;
        }
    }
    return ans;
}

long long solve(long long n, long long k, long long m){
    return 0;
    //return find_pairs(n, k, m);
}

int main(int argc, char const *argv[]) {
    long long n, k;
    long long maxN = 0;
    init();
    std::cin >> n >> k;
    rep(i, n){
        long long x;
        std::cin >> x;
        filledData[x] = true;
        if(maxN < x){
            maxN = x;
        }
    }
    std::cout << solve(n, k, maxN) << '\n';
    return 0;
}
