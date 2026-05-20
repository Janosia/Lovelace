#include <iostream>
#include <vector>

using namespace std;

long long func(vector<int>&candies, int mid){
    long long count = 0;
    for(auto &c : candies) {
        count+= ceil(c/mid)
    }
    return count;
}

int bin_search(vector<int>&candies, int k){
    long long sum = accumulate(candies.begin(), candies.end());
    if(sum < k) return 0;
    int low = 1, high = *max_element(candies.begin, candies.end());
    int ans = INT_MIN;
    while(low <= high){
        int mid = (low+high)/2;
        if(func(candies, mid) > k) {
            ans = max(ans, mid);
            low = mid+1;
        } else high = mid-1;
    }
    return ans;
}