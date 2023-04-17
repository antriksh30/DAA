#include <bits/stdc++.h>
using namespace std;

int matrixChainMemoised(vector<int>&p, int i, int j, vector<vector<int>>&dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k,dp) + 
                    matrixChainMemoised(p, k+1, j,dp) + p[i-1]*p[k]*p[j]);
    }
    return dp[i][j];
}

int main(){
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the dimensions of the matrices: ";
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << "The minimum number of multiplications is: " << matrixChainMemoised(v, 1, n-1,dp) << endl;
    return 0;
}
