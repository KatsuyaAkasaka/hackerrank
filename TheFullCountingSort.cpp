#include <iostream>
#include <string>

const int MAX_N = 1000000;

long long n;
std::string str[MAX_N];
int score[MAX_N];
int key[MAX_N];
std::string output[MAX_N];

int main(int argc, char const *argv[]) {
    for (long long i= 0; i < MAX_N; i++) {
        score[i] = 0;
        key[i] = 0;
    }

    std::cin >> n;
    for (long long i = 0; i < n; i++) {
        int x;
        std::string s;
        std::cin >> x;
        std::cin >> s;
        if(i < n/2){
            s = "-";
        }
        score[x]++;
        str[i] = s;
        key[i] = x;
     }

     for (long long i = 1; i < n; i++) {
         score[i] += score[i-1];
     }

     for(long long i = n-1; i >= 0; i--){
        output[score[key[i]]-1] = str[i];
        score[key[i]]--;
     }

     for (long long i = 0; i < n; i++) {
         std::cout << output[i] << " " ;
     }
     std::cout << '\n';



    return 0;
}
