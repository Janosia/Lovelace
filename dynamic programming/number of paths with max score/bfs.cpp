class Solution {
public:
    int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int R = board.size(), C = board[0].size();
        
        vector<vector<vector<int>>>vis(R, vector<vector<int>>(C, vector<int>(2, 0)));
        vis[R-1][C-1] = {0,1}; // max_score , num_ways
        
        using  T = tuple<int, int ,int>; // max_score, num_ways, row, col
        queue<T>pq;
        pq.push({0, R-1, C-1});
        
        vector<pair<int, int>>dir = {{-1, 0}, {-1, -1}, {0,-1}};
        
        while(!pq.empty()){
            auto [score , r , c] = pq.front();
            // cout << r << " "<<c << " "<<score << " "<< vis[r][c][1]<<endl;
            pq.pop();
            for(auto &d : dir){
                int nr = r + d.first , nc = c + d.second;
                if(nr >= 0 && nc >= 0 && board[nr][nc] != 'X' ){
                    int add = isdigit(board[nr][nc]) ? board[nr][nc] - '0':0;
                    int new_score = score+add;
                    if(new_score > vis[nr][nc][0]){
                        vis[nr][nc][0] = new_score;
                        vis[nr][nc][1] = vis[r][c][1];
                        pq.push({new_score, nr, nc});
                    } else if (new_score == vis[nr][nc][0]){
                        vis[nr][nc][1] = (vis[nr][nc][1] + vis[r][c][1])%mod;
                    } else {continue;}
                }
            }
        }
        return vis[0][0];
    }
};