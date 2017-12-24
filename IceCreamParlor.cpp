#include <iostream>
#include <algorithm>

#define rep(i, t, n) for(int i = t; i < n; i++)

const int MAX_NUM = 10000;
int flavors[MAX_NUM];

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while(t--){
        int m ,n;
        std::cin >> m >> n;
        rep(i, 0, n) std::cin >> flavors[i];
        //std::sort(flavors, flavors+n);
        int ansi, ansj;
        rep(i, 0, n){
            rep(j, 0, n){
            //    std::cout << i << "," << j << '\n';
                if(i == j) continue;
                if(flavors[i] + flavors[j] == m){
                    ansi = i+1;
                    ansj = j+1;
                    goto outer;
                }
                // if(flavors[i] + flavors[j] > m){
                //     break;
                // }
            }
        }
        outer:
        std::cout << ansi << " " << ansj << '\n';
    }
    return 0;
}
