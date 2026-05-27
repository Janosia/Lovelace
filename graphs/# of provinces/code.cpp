class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        int n=isConnected.size();
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i = 0; i<n; i++){
                if(isConnected[temp][i] && !vis[i]){
                    q.push(i);
                    vis[i] =1;
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), out = 0;
        vector<int>vis(n, 0);
        for(int i =0; i<n ; i++){
            if(!vis[i]){
                out++;
                bfs(i, isConnected, vis);
            }
        }
        return out;
    }
};