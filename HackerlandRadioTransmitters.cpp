#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define N 100001

bool cmp(const int a, const int b){
    return a > b;
}

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    int xup[n], xdown[n];
    for(int i = 0; i < n; i++){
        std::cin >> xup[i];
    }
    for(int i = 0; i < n; i++){
        xdown[i] = xup[i];
    }
    std::sort(xup, xup+n);
    std::sort(xdown, xdown+n, cmp);
    int pos = 0;
    int ans = 0;

    while(pos < n){
        for(int i = 0; i < n; i++){
            if(xup[pos] >= xdown[i]-k){
                ans++;
                for(int j = 0; j < n; j++){
                    if(xdown[i]+k < xup[j]){
                        pos = j;
                        break;
                    } else if(j == n-1){
                        pos = n;
                        break;
                    }
                }
                break;
            }
        }
    }

    std::cout << ans << '\n';
    return 0;
}
