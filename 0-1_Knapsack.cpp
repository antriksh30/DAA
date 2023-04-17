#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<int> &w, vector<int> &v, int W, vector<vector<int>> &dp){
    int n = w.size();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << "Maximum value: " << dp[n][W] << endl;
    cout << "Items included: ";
    int i=n, j=W;
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            cout << i << " ";
            j -= w[i-1];
            i--;
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> w(n);
    vector<int> v(n);
    cout << "Enter the weights and values of the items: ";
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    knapsack(w, v, W, dp);

    return 0;
}