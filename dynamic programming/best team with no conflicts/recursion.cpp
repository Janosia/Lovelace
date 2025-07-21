class Solution {
public:
    int recurse(vector<vector<int>>&arr, int idx, int prev_score, int prev_age){
        int N = arr.size();
        if(idx >= N) return 0;
        int take = 0, not_take =0;
        if(arr[idx][0] == prev_age){
            int new_score = max(prev_score, arr[idx][1]);
            take =  arr[idx][1] + recurse(arr, idx+1, new_score, prev_age);
        } else {
            if (arr[idx][1] >= prev_score) {
                take =  arr[idx][1] + recurse(arr, idx+1, arr[idx][1], arr[idx][0]);
            }
        }
        not_take = recurse(arr, idx+1, prev_score, prev_age);
        return dp[{prev_score, prev_age}] = max(take, not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>combined;
        int len = ages.size();
        
        for(int i =0; i<len; i++) combined.push_back({ages[i], scores[i]});
        
        sort(combined.begin(), combined.end());
        
        return recurse(combined, 0, 0,0);
    }
};