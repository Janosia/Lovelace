#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*int upper;
    int recurse(int pos, int home, map<int, int>&forbid, int a, int b, bool can_back, vector<vector<int>>&dp){
        if( pos == home ) return 0;
        if( forbid[pos] >= 1 || pos >= upper) return 1e9;
        if(dp[pos][can_back] != -1) return dp[pos][can_back];
        int frwd = 1e9, bkwd = 1e9;
        if( can_back && pos-b >= 0){
            bkwd = 1 + recurse(pos - b, home, forbid, a , b , false, dp);
        }
        frwd = 1 + recurse(pos+a, home, forbid, a, b, true, dp);
        return dp[pos][can_back] = min(bkwd, frwd);
    }*/
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int>mp (forbidden.begin(), forbidden.end());
        int upper = *max_element(forbidden.begin(), forbidden.end())+a+b; 
        upper = max(upper, x+b);
        // cout << "Upper limit : "<< upper << endl;
        vector<vector<int>>dp(upper+1, vector<int>(2, INT_MAX));
        using T = tuple<int, int, bool>;
        queue<T>pq;
        pq.push({0,0, true});
        dp[0][1] = 0;
        while(!pq.empty()){
            auto [step, pos, can_back] = pq.front();
            pq.pop();
            // cout << pos << " steps "<< step << " Reverse :"<< can_back<<  " pos-b:"<<pos-b << endl;  
            if(pos == x) return step;
            if(pos + a <= upper && mp.count(pos+a) == 0 && dp[pos+a][true] > step+1){
                pq.push({step+1, pos+a, true});
                dp[pos+a][true] = step+1;
            } 
            
            if(can_back && pos - b >= 0 && mp.count(pos-b) == 0 && dp[pos-b][false] > step+1){
                pq.push({step+1, pos-b, false});
                dp[pos-b][false] = step+1;
            } 
        }
        return -1;
    }
};