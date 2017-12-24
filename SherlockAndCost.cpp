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
    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        int b[N];
        for(int i = 0; i < N; i++){
            std::cin >> b[i];
        }
        int score[N][2];
        memset(score, 0, sizeof(score));

        

        for(int i = 1; i < N; i++){
            score[i][0] =
            std::max(score[i-1][0] + std::fabs(b[i]-b[i-1]), score[i-1][1] + std::fabs(b[i]-1));

            score[i][1] =
            std::max(score[i-1][0] + std::fabs(1-b[i-1]), score[i-1][1] + std::fabs(1-1));
        }

        std::cout << std::max(score[N-1][0], score[N-1][1]) << '\n';

    }
    return 0;
}
