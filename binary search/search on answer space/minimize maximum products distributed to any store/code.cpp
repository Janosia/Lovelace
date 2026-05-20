#include <iostream>
#include <vector>

using namespace std;

long long func(vector<int>&qt_prod, int mid){
    long long count = 0;
    for(auto &q : qt_prod) count += ceil((double) q / (double) mid);
    return count;
}

int bin_search(vector<int>&qt_prod, int n){
    if (n==1) return qt_prod[0];
    int low = 1, high = *max_element(qt_prod.begin(), qt_prod.end());
    while(low <= high){
        int mid = (low+high)/2;
        if(func(qt_prod, mid) > n) low = mid+1;
        else high = mid-1;
    }
    return low;
}