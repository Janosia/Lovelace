#include <iostream>
#include <vector>

using namespace std;

long long func(vector<int> & piles, int mid){
    int total_time = 0;
    for(auto p : piles){
        total_time = ceil((double) p / (double) mid); 
    }
    return total_time;
}

int bin_search(vector<int> & piles, int h){
    int low = 1, high = *max_element(piles.begin(), piles.end());

    while(low <= high){
        int mid = (low+high)/2;
        long long  t = func(piles, mid);
        if( t > h){
            low = mid+1;
        } else high = mid-1;
    }
    return low;
}