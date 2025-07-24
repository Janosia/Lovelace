#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int len = obstacles.size();
        int last =  len-1;
        // cout << "End point "<< last<<endl;
        vector<vector<int>>dp(4,vector<int>(len+1, INT_MAX));
        for(int i =0; i<len ; ++i){
            if(obstacles[i] == 0) continue;
            else{
                int y = i, x= obstacles[i];
                // cout << x << " "<< y <<endl;
                dp[x][y] = -1; // mark as cannot be visited;
            }
        }
        // types of jumps {-1, 1, -2, 2} ensure that the jump is not taking us to 
        // 0 or 4 stop once i reach 
        using T = tuple<int, int,int>; // side steps, row, point;
        priority_queue<T, vector<T>, greater<T>>pq;
        pq.push({0, 2, 0});
        vector<int>dir = {-1, 1, -2, 2};
        while(!pq.empty()){
            auto [step, row, point] = pq.top();
            pq.pop();
            if(point == last) return step;
            int new_y = point+1;
            if(dp[row][new_y] != -1 ){
                if(dp[row][new_y] > step){
                    pq.push({step, row, new_y});
                    dp[row][new_y] = step;
                }
            } else {
                // int new_x =0;
                for(auto &d : dir){
                    int new_x = row + d;
                    if(new_x <= 3 && new_x > 0 && dp[new_x][point] != -1){
                        if(dp[new_x][point] > step+1){
                            pq.push({step+1, new_x, point});
                            dp[new_x][point] = step+1;
                        }
                    }
                }
            }
        }
        return -1; 
    }
};