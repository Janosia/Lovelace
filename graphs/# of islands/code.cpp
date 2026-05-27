class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, n = grid.size(), m = grid[0].size();
        queue<vector<int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<pair<int, int>>dir = {  {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i =0; i<n; i++){
            for(int j =0; j <m ; j++){
                if(grid[i][j] != '0' && !vis[i][j]){
                    count++;
                    vis[i][j] = 1;
                    q.push({i, j});
                    // cout << "BFS called for : "<< i << " "<< j <<endl;
                    while(!q.empty()){
                        vector<int>temp = q.front();
                        q.pop();
                        // cout << "Vis. node " << temp[0] <<" "<<temp[1]<<endl;
                        for(auto &p : dir){
                            int nr = temp[0]+p.first, nc = temp[1]+p.second;
                            if(nr >= 0 && nr < n && nc >=0 && nc < m ){
                                
                                if(!vis[nr][nc] && grid[nr][nc] == '1'){
                                    // cout << "Land "<< nr << " "<<nc <<endl;
                                    q.push({nr, nc});
                                    vis[nr][nc] = 1;
                                }
                            }
                             
                        }
                    }
                    
                }
            }
        }
        return count;
    }
};