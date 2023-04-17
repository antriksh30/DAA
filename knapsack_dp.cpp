#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                              dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    int items;
    cout<<"Enter the number of items: ";
    cin>>items;
    int profit[items], weight[items];
    for(int i=0; i<items; i++){
        cout<<"Enter the profit and weight of item "<<i+1<<": ";
        cin>>profit[i]>>weight[i];
    }
    
    int W;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>W;

    cout << "Maximum profit is: " << knapSack(W, weight, profit, items) << endl;


    return 0;
}


// C++ program for the above approach

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the maximum profit
// int knapSack(int W, int wt[], int val[], int n)
// {
// 	// Making and initializing dp array
// 	int dp[W + 1];
// 	memset(dp, 0, sizeof(dp));

// 	for (int i = 1; i < n + 1; i++) {
// 		for (int w = W; w >= 0; w--) {

// 			if (wt[i - 1] <= w)
				
// 				// Finding the maximum value
// 				dp[w] = max(dp[w],
// 							dp[w - wt[i - 1]] + val[i - 1]);
// 		}
// 	}
// 	// Returning the maximum value of knapsack
// 	return dp[W];
// }

// // Driver code
// int main()
// {
// 	int profit[] = { 60, 100, 120 };
// 	int weight[] = { 10, 20, 30 };
// 	int W = 50;
// 	int n = sizeof(profit) / sizeof(profit[0]);
// 	cout << knapSack(W, weight, profit, n);
// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
 
// // Returns the value of maximum profit
// int knapSackRec(int W, int wt[], int val[], int i, int** dp)
// {
//     // base condition
//     if (i < 0)
//         return 0;
//     if (dp[i][W] != -1)
//         return dp[i][W];
 
//     if (wt[i] > W) {
 
//         // Store the value of function call
//         // stack in table before return
//         dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
//         return dp[i][W];
//     }
//     else {
//         // Store value in a table before return
//         dp[i][W] = max(val[i]
//                            + knapSackRec(W - wt[i], wt, val,
//                                          i - 1, dp),
//                        knapSackRec(W, wt, val, i - 1, dp));
 
//         // Return value of table after storing
//         return dp[i][W];
//     }
// }
 
// int knapSack(int W, int wt[], int val[], int n)
// {
//     // double pointer to declare the
//     // table dynamically
//     int** dp;
//     dp = new int*[n];
 
//     // loop to create the table dynamically
//     for (int i = 0; i < n; i++)
//         dp[i] = new int[W + 1];
 
//     // loop to initially filled the
//     // table with -1
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < W + 1; j++)
//             dp[i][j] = -1;
//     return knapSackRec(W, wt, val, n - 1, dp);
// }
 
// // Driver Code
// int main()
// {
//     int profit[] = { 60, 100, 120 };
//     int weight[] = { 10, 20, 30 };
//     int W = 50;
//     int n = sizeof(profit) / sizeof(profit[0]);
//     cout << knapSack(W, weight, profit, n);
//     return 0;
// }