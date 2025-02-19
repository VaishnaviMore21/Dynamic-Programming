class Solution {

 static int getAns(int arr[], int n, int ind, int prev_index, int[][] dp) 
    {
      if(ind==n)
      {
        return 0;
      }
      if(dp[ind][prev_index+1]!=-1)
      {
        return dp[ind][prev_index+1];
      }
      int notTake=0+getAns(arr,n,ind+1,prev_index,dp);
      int take=0;
         if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }

        dp[ind][prev_index + 1] = Math.max(notTake, take);
         return dp[ind][prev_index + 1];
    
    }


    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        int dp[][]=new int[n][n+1];
        for(int row[]:dp)
        {
            Arrays.fill(row,-1);
        }
        return getAns(nums,n,0,-1,dp);
    }
}
