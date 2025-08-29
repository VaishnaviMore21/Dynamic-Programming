class Solution {
    
    public long countWaysUtil(int[]coins,int ind,int sum,long[][]dp)
    {
        if(ind==0)
        {
            return (sum % coins[0] == 0) ? 1 : 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        long notTake=countWaysUtil(coins,ind-1,sum,dp);
        long take=0;
        if(coins[ind]<=sum)
        {
            take=countWaysUtil(coins,ind,sum-coins[ind],dp);
            
        }
        return dp[ind][sum] = notTake + take;
    }
    public int count(int coins[], int sum) {
        // code here.
                int n = coins.length;
        long[][] dp = new long[n][sum + 1];

        // Initialize dp array with -1
        for (long[] row : dp) Arrays.fill(row, -1);

        return (int) countWaysUtil(coins, n - 1, sum, dp);
    }
}
