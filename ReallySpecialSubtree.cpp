#include <iostream>
#include <vector>
#include <algorithm>


struct edges{
    int x, y;
    long long r;
};

const int max_array = 3000;

int N;
long long M;
std::vector<edges> v;
long long score = 0;
int parent[max_array];      //それぞれの木の根が代入されている
int sizes[max_array];


bool cmp(edges a, edges b){
    return a.r < b.r;
}

int find(int x){
    if(x != parent[x]){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y, long long r){
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    } else {
        if(sizes[x] < sizes[y]){    //swap -> x > y
            int tmp = x;
            x = y;
            y = tmp;
        }
        parent[y] = x;
        sizes[x] += sizes[y];
        sizes[y] = 0;
        score += r;
    }
    return;
}

void kruskal(){
    for(long long i = 0; i < M; i++){
        unite(v[i].x, v[i].y, v[i].r);
    }
}

int main(int argc, char const *argv[]) {
    std::cin >> N >> M;
    for(int i = 0; i < N; i++){
        parent[i] = i;
        sizes[i] = 1;
    }
    for(long long i = 0; i < M; i++){
        edges e;
        std::cin >> e.x >> e.y >> e.r;
        v.push_back(e);
    }
    std::sort(v.begin(), v.end(), cmp);
    kruskal();
    std::cout << score << '\n';
    return 0;
}
