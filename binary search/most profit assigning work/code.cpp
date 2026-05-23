class Solution {
public:
    int bin_search (vector<vector<int>>&items, int target){
        int low = 0, high= items.size()-1, ans= INT_MIN;
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>>items;
        int n = difficulty.size();
        
        for(int i =0; i<n; i++){
            vector<int>temp = {difficulty[i], profit[i]};
            items.push_back(temp);
        }
        sort(items.begin(), items.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0];
        });
        for(int i =1; i<n; i++){
            items[i][1] = max(items[i][1], items[i-1][1]);
        }
        for(int i =0; i<n; i++){
            cout << "( "<<items[i][0] <<" "<< items[i][1] <<")"<<endl;
        }
        int ans = 0;
        for( auto &w : worker){
            ans+= bin_search(items, w);
        }
        return ans;
    }
};