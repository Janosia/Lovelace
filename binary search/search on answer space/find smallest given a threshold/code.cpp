#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>&nums, int div){
    int count = 0 ;
    for(auto &n : nums) count += ceil((double) n / (double) div);
    return count 
}

int bin_search(vector<int>&nums, int threshold){
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while(low<=high){
        int mid = (low+high)/2;
        if(func(nums, mid) > threshold) low = mid+1;
        else high = mid-1;
    }
    return low;
}