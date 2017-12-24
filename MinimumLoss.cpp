#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

struct Vec {
    long long p;
    long long order;
};

std::vector<Vec> v;

bool cmp(Vec a, Vec b){
    return a.p < b.p;
}

int main(int argc, char const *argv[]) {
    long long n;
    std::cin >> n;
    for(long long i = 0; i < n; i++){
        Vec a;
        std::cin >> a.p;
        a.order = i;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end(), cmp);
    long long min = INT_MAX;

    for(long long i = 1; i < n; i++){
        long long score = v[i].p - v[i-1].p;
        if(score < min && score > 0 && v[i].order < v[i-1].order){
            min = score;
        }
    }
    std::cout << min << '\n';
    return 0;
}
