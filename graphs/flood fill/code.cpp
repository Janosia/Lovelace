class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> dir = {{0, 1}, {0,-1}, {1 ,0}, {-1, 0}};
        queue<vector<int>>q;
        int n = image.size(), m = image[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        q.push({sr, sc});
        while(!q.empty()){
            vector<int>temp = q.front();
            q.pop();
            int r = temp[0], c = temp[1], cl = image[r][c]; 
            vis[r][c] = 1, image[r][c] =  color;
            for(auto p : dir){
                int nr = r+p.first, nc = c+p.second;
                if(nr >= 0 && nr < n && nc >=0 && nc < m){
                    if(image[nr][nc] == cl && !vis[nr][nc]){
                        q.push({nr, nc});
                    }
                }
            }
        }
        return image;
    }
};