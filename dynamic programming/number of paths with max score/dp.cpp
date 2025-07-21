class Solution {
public:
    int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int R = board.size(), C = board[0].size();
        
        vector<vector<vector<int>>>vis(R, vector<vector<int>>(C, vector<int>(2, 0)));
        
        vis[R-1][C-1] = {0,1};
        for(int i = R-1 ; i>=0 ; --i){
            for(int j = C-1 ; j>=0 ; --j){
                if(i == R-1 && j == C-1) {
                    continue;
                }
                if(board[i][j] == 'X'){
                    continue;
                } else{
                    int add = isdigit(board[i][j]) ? board[i][j]-'0':0;
                    int right = 0, down = 0, diag = 0 , rw =0, dgw=0, dw=0;
                    if( j+1 < C) {
                        right = vis[i][j+1][0];
                        rw = vis[i][j+1][1];
                    }
                    if(i+1 < R && j+1 <C){
                        diag = vis[i+1][j+1][0];
                        dgw = vis[i+1][j+1][1];
                    } 
                    if(i+1 < R) {
                        down = vis[i+1][j][0];
                        dw = vis[i+1][j][1];
                    }
                    int ways = 0;
                    
                    if(right == down && down == diag){
                        ways = (rw+dgw+dw)%mod;
                        vis[i][j][0] = add + right;
                    } else if (right == down && down > diag){
                        ways = (rw+dw)%mod;
                        vis[i][j][0] = add + right;
                    } else if (right < down && down == diag) {
                        ways = (dw+dgw)%mod;
                        vis[i][j][0] = add + down;
                    } else if (right == diag && right > down){
                        ways = (rw+dgw)%mod;
                        vis[i][j][0] = add + right;
                    } else {
                        if (right > down && right > diag){
                            ways = rw%mod;
                            vis[i][j][0] = add + right;
                        } else if (down > right && down > diag){
                            ways = dw%mod;
                            vis[i][j][0] = add + down;
                        } else {
                            ways = dgw%mod;
                            vis[i][j][0] = add + diag;
                        }
                    }
                    vis[i][j][1] = ways;
                }
            }
        }
        if(vis[0][0][1] == 0) return {0,0};
        return vis[0][0];
    }
};