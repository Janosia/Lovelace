#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<vector<int>>&items, int target){
    int low = 0, high = items.size() -1;
    int ans = INT_MIN;
    while(low <= high){
        int mid = (low+high)/2;

        if(items[mid][0] > target) high = mid-1;
        else {
            ans = max(ans, items[mid][1]);
            low = mid+1;
        }
    }
    return ans == INT_MIN ? 0 : ans;
}

vector<int> function(vector<vector<int>>items, vector<int>&queries){

    sort(items.begin(), items.end(), [](const vector<int>&a, vector<int>&b{
        return a[0] < b[0];
    }));

    for(int i =1; i<items.size(); i++){
        items[i][1] = max(items[i][1], items[i-1][1]);
    }
    vector<int>arr;
    for(auto &q: queries) {
        int temp = bin_search(items, q);
        arr.push_back(q);
    }
    return arr;
}