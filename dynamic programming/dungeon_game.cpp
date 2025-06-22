#include<iostream>
#include<vectors>

using namespace std;

int recurse(vector<vector<int>> &dungeon, vector<vector<int>> &dp, int r, int c){
    if(dp[r][c]!=INT_MAX)return dp[r][c];
    
    dp[r][c] = max(dungeon[r][c]+recurse(dungeon, dp, r+1,c), dungeon[r][c]+recurse(dungeon, dp, r, c+1));
    
    return dp[r][c] = dp[r][c]>0 ? 0:dp[r][c];
}
    
int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size(), c = dungeon[0].size();
        vector <vector<int>> dp;
        
        for(int i =0; i<r; i++){
            vector<int> temp;
            for(int j =0; j<c; j++) temp.push_back(INT_MAX);
            dp.push_back(temp);
        }
        
        if(dungeon[r-1][c-1]>0){dp[r-1][c-1]=0;}
        else {dp[r-1][c-1] = dungeon[r-1][c-1];}
        
        for(int i=c-2; i>=0; i--){
            dp[r-1][i] = dungeon[r-1][i] + dp[r-1][i+1];
            if(dp[r-1][i]>0) dp[r-1][i] = 0;}
        for(int j =r-2; j>=0; j--){
            dp[j][c-1] = dungeon[j][c-1]+ dp[j+1][c-1];
            if(dp[j][c-1]>0) dp[j][c-1] =0}
        
        int h = recurse(dungeon, dp,0, 0);
        
        if(h>1) return 1;
        else if( h==0 ) return 1;
        else if(h<0){
            h *=-1;
            h++;
        }
        return h;
}
