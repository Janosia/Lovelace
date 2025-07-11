#include <iostream>
#include <vector>
#include <string>

int main(string word1, string word2){
    int n1 = word1.size(), n2 = word2.size();
    
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, (n1+n2)*n2));
    
    for(int i = 0; i < n2+1; i++) dp[n1][i] = n1-i;
    for(int j = 0; j < n1+1; j++) dp[j][n2] = n2-i;
    
    for(int i = n1-1; i >= 0; i--){
        for(int j = n2-1; j >= 0; j--){
            if(word1[i] == word2[j]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }else{
                dp[i][j] = min(dp[i][j], dp[i+1][j] + 1); // delete character from word1
                dp[i][j] = min(dp[i][j], dp[i+1][j+1] + 1); // replace character
                dp[i][j] = min(dp[i][j], dp[i][j+1] + 1); // insert character
            }
        }
        return dp[0][0];
    }

}