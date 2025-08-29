class Solution {
public static int minimumCoinsUtil(int[]arr,int ind, int T, int[][] dp)
{
    if(ind==0)
    {
        if(T%arr[0]==0)
        {
            return T/arr[0];
        }
        else
        {
             return (int) Math.pow(10, 9);
        }
    }
    if(dp[ind][T]!=-1)
    {
        return dp[ind][T];
    }
    int notTaken=0+minimumCoinsUtil(arr,ind-1,T,dp);
     int taken = (int) Math.pow(10, 9);

        // If the current element is less than or equal to T, calculate the minimum taking it
        if (arr[ind] <= T)
            taken = 1 + minimumCoinsUtil(arr, ind, T - arr[ind], dp);

return dp[ind][T] = Math.min(notTaken, taken);
}
    public int minCoins(int coins[], int T) {
        // code here
        
        int n=coins.length;
        int[][]dp=new int[n][T+1];
        for(int row[]:dp)
        {
            Arrays.fill(row,-1);
        }
        
        int ans=minimumCoinsUtil(coins,n-1,T,dp);
         if (ans >= (int) Math.pow(10, 9))
            return -1;
        return ans;
    }
}
