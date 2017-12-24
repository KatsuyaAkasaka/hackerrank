#include <math.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#define N 1000

std::vector<int> v;
bool isused[N];
int ans = 0;


int rec_paturn(int node){
    for(int i = 0; i < node; i++){

        if(v.size() == node){       //ノードをすべてvectorにいれたら
            for(int j = 0; j < node; j++){  //出力
                std::cout << v[j] << " ";
            }
            std::cout << '\n';
            ans++;
            break;
        }
        if (!isused[i]){                //使われていないものを見つけたら
            isused[i] = true;           //isusedにして
            v.push_back(i);             //vにpushして
            ans = rec_paturn(node);    //再帰
            isused[v.back()] = false;
            v.pop_back();               //pop
        }
    }
    return ans;
}

bool error_check(float n){
    if(n < 0){
        std::cout << "正の整数を入力してください" << '\n';
        return false;
    }
    if(ceilf(n) != floorf(n)){
        std::cout << "整数を入力してください" << '\n';
        return false;
    }
    if(n > N){
        std::cout << N << "以下の値を入力してください" << '\n';
        return false;
    }
    return true;
}


int solve(int node){
    return rec_paturn(node);
}

int main(int argc, char const *argv[]){
    float node_num;
    bool iserror = false;

    while (!iserror){
        std::cin >> node_num;
        iserror = error_check(node_num);
    }

    std::cout << "パターン数 : " << solve((int)node_num) << '\n';
    return 0;
}
