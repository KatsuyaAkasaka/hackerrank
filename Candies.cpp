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

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    std::cin >> N;
    std::vector<int> v;
    int score[N];
    for(int i = 0; i < N; i++){
        score[i] = 1;
    }
    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < N-1; i++){
        if(v[i+1] > v[i]){
            score[i+1] = score[i]+1;
        }
        //std::cout << "first" << score[i] << '\n';
    }
    //std::cout << "first" << score[N-1] << '\n';

    for(int i = N-2; i >= 0; i--){
        if(v[i+1] < v[i]){
            score[i] = std::max(score[i], score[i+1]+1);
        }
    }
    long long sum = 0;
    for(int i = 0; i < N; i++){
    //    std::cout << score[i] << '\n';
        sum += score[i];
    }
    std::cout << sum << '\n';
    return 0;
}
