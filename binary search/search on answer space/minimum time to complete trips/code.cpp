#include <iostream>
#include <vector>

using namespace std;

long long func(vector<int>&time, long long mid){
    long long count = 0;
    for(auto &t : time) count += ceil (mid /t);
    return count;
}

long long bin_search(vector<int>&time, int totaltrips){
    long long low =1, high = *max_element(time.begin(), time.end());
    high *=totaltrips;
    while(low <= high){
        long long mid  = (low+high)/2;
        if( func(time, mid) < totaltrips) low  = mid + 1;
        else high = mid - 1; 
    }
    return low;
}