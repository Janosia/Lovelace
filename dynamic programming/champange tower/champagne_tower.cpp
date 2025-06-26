#include <iostream>
#include <vector>

int main(double poured, int qr, int qc){
    if(!poured) return 0;
    if(poured ==1 && qr>0) return 0;
    if(qr == 0) return min(1.0, poured);
    
    vector<vector<double>>dp(qr+1, vector<double>(qr+2, 0));
    dp[0][0] =0, dp[0][1]=poured;
        
    if(qr>=1)dp[1][0] = (poured-1)/2.0, dp[1][1]=dp[1][0];
    
    for(int i =2; i<qr+1; i++){
        for(int j =0; j<=i; j++){
            if(j == 0){
            if( dp[i-1][j]>1 ) dp[i][j] = (dp[i-1][j]-1)/2.0;
            } 
            else if (i==j){
            if( dp[i-1][j-1]>1 ) dp[i][j] =(dp[i-1][j-1]-1)/2.0;
            } 
            else {
            if(dp[i-1][j]>1) dp[i][j] = (dp[i-1][j]-1)/2.0;
            if(dp[i-1][j-1]>1) dp[i][j] += (dp[i-1][j-1]-1)/2.0;
            }
            dp[i][j]=max(0.0, dp[i][j]); 
        }
    }
    return min(1.0,dp[qr][qc]);
}