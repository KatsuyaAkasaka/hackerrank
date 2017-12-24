#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    std::vector<int> v;
    for(int i = 0; i< n; i++){
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int count = 0, searchingNum = 0, pos = 0;
    for(searchingNum = 0; searchingNum <= 99; searchingNum++){
        while(v[pos] == searchingNum){
            count++;
            pos++;
        }
        std::cout << count << " ";
        count = 0;
    }
    std::cout << '\n';

    return 0;
}
