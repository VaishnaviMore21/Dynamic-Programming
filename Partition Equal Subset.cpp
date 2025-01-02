class Solution {
public:
    bool f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(target==0)return true;
        if(ind==0)return (arr[0]==target);
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notTake=f(ind-1,target,arr,dp);
        bool take=false;
        if(arr[ind]<=target)
        {
         take=f(ind-1,target-arr[ind],arr,dp);
             
        }
       return dp[ind][target]= take|notTake;
    }
  
  
  
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
         int n=nums.size();
        for (int i = 0; i < n; i++) {
        totSum += nums[i];
          }
          if(totSum % 2)return false;
          int target=totSum/2;
          vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Call the subsetSumUtil function to check if it's possible to partition
        return f(n - 1, target, nums, dp);
       

    }
};
