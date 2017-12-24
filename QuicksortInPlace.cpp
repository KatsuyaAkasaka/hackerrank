#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int num;

void quicksort(int ary[], int left, int right){

    int l = left, r = left;
    int pivot = ary[right];

    if(left == right){
        return;
    }
    while(true){
        while(ary[l] < pivot){
            l++; r++;
        }
        while(ary[r] > pivot){
            r++;
        }
        int tmp = ary[l];
        ary[l] = ary[r];
        ary[r] = tmp;
        if(r == right) break;

        //std::cout << left << right << "の時ので" << l << r << '\n';
        r = l;
    }

    for(int i = 0; i < num; i++){
        std::cout << ary[i] << " ";
    }
    std::cout << '\n';
    if(l-1 - left >= 1) quicksort(ary, left, l-1);
    if(r - l - 1 >= 1) quicksort(ary, l+1, right);
    return;
}

int main() {
    std::cin >> num;
    int ary[num];

    for(int i = 0; i < num; i++){
        std::cin >> ary[i];
    }
    quicksort(ary, 0, num-1);  //ary, left, right, pivot

    return 0;
}
