#include <iostream>
#include <vector>

using namespace std;

int bin_search(int target){
    int low = 1 , high = target;
    int ans = low;
    while(low <= high){
        long long mid = (low+high)/2, sqr = mid * mid;

        if(sqr <= target){
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}