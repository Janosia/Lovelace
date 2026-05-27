class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>>dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int out = 0;
        queue<vector<int>>q;
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j] == 2 ) {
                    q.push({i, j, 0});
                    // cout << "Rotten orange @ "<< i << " , "<<j<<endl;
                }  
            }
        }
        while(!q.empty()){
            vector<int>temp = q.front();
            q.pop();
            int r = temp[0], c = temp[1], t = temp[2];
            out = max(out, t);
            vis[r][c] = 1;
            for(auto p : dir){
                int nr = r + p.first, nc = c+ p.second;
                if(nr >= 0 && nr < n && nc >= 0 && nc <m){
                    if(vis[nr][nc] == 0 && grid[nr][nc] == 1){ 
                        q.push({nr, nc, t+1});
                        grid[nr][nc] = 2;
                        // cout << "New rotten orange @ "<< nr <<" ," <<nc<<endl;
                    }
                }
            } 
        }
        for(int i =0; i<n ; i++){
            for (int j =0; j<m ; j++) if (grid[i][j] == 1) return -1;
        }
        return out;
    }
};