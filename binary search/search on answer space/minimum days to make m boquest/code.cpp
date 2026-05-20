#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>&BloomDays, int day, int k){
    int boq = 0, count =0;
    for(auto fl : BloomDays){
        if(fl <=mid ) count ++;
        else{
            boq+= (double)count/ double(k);
            count =0;
        }
    }
    boq+= (double)count/ double(k);
    return boq;
}

int bin_search(vector<int>&BloomDays, int m, int k){
    long long num_flowers_needed = (long) m * (long) k ;

    if(num_flowers_needed > BloomDays.size()) return -1;

    int low = *min_element(BloomDays.begin(), BloomDays.end());
    int high = *max_element(BloomDays.begin(), BloomDays.end());

    while(low <= high){
        int mid = (low+high)/2;

        int num_boq =. func(BloomDays, mid, k);
        if(num_boq < m) low = mid+1;
        else high = mid-1;
    }
    return low ;
}