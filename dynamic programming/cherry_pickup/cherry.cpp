#include <iostream>

using namespace std;

int dp[105][105][105];

long long solve(int i, int j, int p , vector<vector<char>>&maze){
    int q = i+p-j, h = maze.size(), w = maze[0].size();
    if( i>=h || i<0 || j >=w || j <0 || x>=h || y>=w || x<0 || y<0 || maze[i][j] =='#' || maze[x][y] == '#') return 0;
    if(i == h-1 && j == w-1 && p == h-1 &&  q == w-1) return maze[i][j] == '*' ? 1:0;
    if (dp[i][j][p]!=-1) return dp[i][j][p];
    
    dp[i][j][p] = max(LONG_MIN, solve(i + 1, j , x + 1, maze));
    dp[i][j][p] = max(dp[i][j][p], solve(i, j + 1, x + 1, maze));
    dp[i][j][p] = max(dp[i][j][p], solve(i + 1, j, x, maze));
    dp[i][j][p] = max(dp[i][j][p], solve(i, j + 1, x, maze));
    return dp[i][j][p];
}

int main(){

}