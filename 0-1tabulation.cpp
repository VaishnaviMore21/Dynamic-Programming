//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        // Create a DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base condition: Fill in the first row for the weight of the first item
        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = val[0];
        }

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                // Calculate the maximum value by either excluding the current item or including it
                int notTaken = dp[ind - 1][cap];
                int taken = INT_MIN;

                // Check if the current item can be included without exceeding the knapsack's capacity
                if (wt[ind] <= cap) {
                    taken = val[ind] + dp[ind - 1][cap - wt[ind]];
                }

                // Update the DP table
                dp[ind][cap] = max(notTaken, taken);
            }
        }

        // The final result is in the last cell of the DP table
        return dp[n - 1][W];
    }

    // Function to return max value that can be put in knapsack of capacity
    int knapSack(int capacity, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        return knapsack(wt, val, n, capacity);
    }
};

//{ Driver Code Starts.

