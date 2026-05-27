#include <iostream>
#include <vector>

using namespace std;

double func(vector<int>&dist, int speed){
    double count = 0;
    int n = dist.size() -1;
    for(int i =0; i<n ; i++){count += ceil((double)dist[i]/ (double)speed);}
    count+= (double) dist[n] / (double) speed;
    return count;
}

int bin_search(vector<int>&dist, double hours){
    int low = 1, high = 1e7;

    while(low <= high){
        int mid = (low+high)/2;

        if(func(dist, mid) > hours) low = mid+1;
        else high = mid-1;
    }
    return low <= 1e7 ? low : -1;
}