#include <iostream>
#include <vector>
using namespace std;

int find_unique(vector<int>nums){
    int ans = 0;
    for(auto n : nums) ans = ans^n;
    return ans;
}