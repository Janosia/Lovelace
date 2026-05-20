#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>&wts, int wt){
    int count =0, days =0;

    for (auto &w : wts){
        if(count +w <= wt) count+=w;
        else{
            days++;
            count = w;
        }
    }
    return days;
}

int bin_search(vector<int>&wts, int day){
    int low = *max_element(wts.begin(), wts.end());
    int high = accumulate(wts.begin(), wts.end());
    while(low<=high){
        int mid = (low+high)/2;
        if(func(wts, mid) > day) low = mid+1;
        else high = mid-1;
    }
    return low;
}