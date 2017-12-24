#include <iostream>

long long fib(long long a ,long long b, int n){
    long long score;
    n--;
    std::cout << b << '\n';
    if(n > 0){
        score = fib(b, b*b+a, n);
    } else {
        return b;
    }
    return score;
}

int main(int argc, char const *argv[]) {
    long long a, b;
    int n;
    std::cin >> a >> b >> n;
    n = 20;
    std::cout << fib(a, b, n) << '\n';
    return 0;
}
