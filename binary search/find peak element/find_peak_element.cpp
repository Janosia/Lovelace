#include <iostream>
#include <vector>
using namespace std;

int find_peak(vector<int>nums){
    int n = nums.size(), low =1, high = n-2;
    if(n==1) return nums[0];
    if(nums[0] > nums[1]) return nums[0];
    if(nums[n-1] > nums[n-2]) return nums[n-1];

    while(low <= high){
        int mid = (low+high)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return nums[mid];

        if(nums[mid] >  nums[mid-1] && nums[mid] < nums[mid+1]){
            low = mid+1;
        } else { high = mid-1 ;}
    }
    return -1;
}