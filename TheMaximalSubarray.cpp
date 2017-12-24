#include <iostream>
#include <limits.h>

int T;
long long N;
int main(int argc, char const *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        long long current_max = INT_MIN;
        int maxNum = INT_MIN;
        long long contmax = INT_MIN;
        long long notcontmax = 0;

        for(int i = 0; i < N; i++){
            long long a;
            std::cin >> a;
            current_max = std::max(a,current_max + a);
            contmax = std::max(current_max,contmax);
            if(maxNum < a){  //最大値検索
                maxNum = a;
            }
            if(a > 0){       //positiveNumber加算
                notcontmax += a;
            }
        }

        if(notcontmax == 0){
            notcontmax = maxNum;
        }

        std::cout << contmax << " " << notcontmax << '\n';
    }
    return 0;
}
