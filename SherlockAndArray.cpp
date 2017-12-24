#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define f(i, 0, n) for(int i = 0; i < n; i++)

char* solve(int *top){
    int left_sum = 0;   //temporaly left_sum
    int right_sum = 0;  //tempolary right_sum
    int left_pointer = 0;
    int right_pointer = n;

}

int main() {
    int T;  //the number of test_case
    int n;  //the Array_length

    std::cin >> T;
    while(T--){
        std::cin >> n;
        int array[n];
        f(i, 0, n){
            int a;
            std::cin >> a;
            array[i] = a;
        }
        solve(array);
    }
    std::cout << "YES" << '\n';
    std::cout << "NO" << '\n';
    return 0;
}
