#include <iostream>
#include <vector>
using namespace std;

int find_mininmum(vector<int>nums){
    int n = nums.size(), low =0, high = n-1, ans = INT_MAX;

    while(low <= high){
        int mid = (low+high)/2;

        if(nums[low] <= nums[high]){
            ans = min(ans, nums[low]);
            return ans;
        }
        if(nums[low] >= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid+1;
        } else {
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return -1;
}