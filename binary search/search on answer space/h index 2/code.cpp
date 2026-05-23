class Solution {
public:
    int func(vector<int>&citations, int mid){
        int count =0 ;
        for(auto &c:citations){
            if(c >= mid) count++;
        }
        return count;
    }
    int hIndex(vector<int>& citations) {
        int low  =0, high = *max_element(citations.begin(), citations.end());
        int ans = 0;
        while (low<=high){
            int mid = (low+high)/2;
            if(func(citations, mid) < mid) high = mid - 1;
            else {
                ans = max(ans, mid);
                low = mid+1;  
            }
        }
        return ans;
    }
};