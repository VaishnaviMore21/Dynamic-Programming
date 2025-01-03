int myfun(vector<int>& wt, vector<int>& val, int ind, int capacity, vector<vector<int>>& dp) {
        // Base Case: No items left or no capacity left
        if (ind < 0 || capacity == 0) {
            return 0;
        }

        // If the result is already computed, return it
        if (dp[ind][capacity] != -1) {
            return dp[ind][capacity];
        }

        // Case 1: Not taking the current item
        int notTake = myfun(wt, val, ind - 1, capacity, dp);

        // Case 2: Taking the current item (if it fits)
        int take = 0;
        if (wt[ind] <= capacity) {
            take = val[ind] + myfun(wt, val, ind - 1, capacity - wt[ind], dp);
        }

        // Store the result in the DP table and return the maximum value
        return dp[ind][capacity] = max(notTake, take);
    }

    int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        // Create a DP table and initialize it with -1
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return myfun(wt, val, n - 1, W, dp);
    }

    // Function to return max value that can be put in knapsack of capacity
    int knapSack(int capacity, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        return knapsack(wt, val, n, capacity);
    }
};
