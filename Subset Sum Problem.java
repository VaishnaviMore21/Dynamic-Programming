import java.util.Arrays;

class Solution {

    static boolean subsetSumUntil(int ind, int target, int[] arr, int[][] dp) {
        if (target == 0) return true;

        if (ind == 0) return arr[0] == target;

        if (dp[ind][target] != -1) return dp[ind][target] == 1;

        boolean nottake = subsetSumUntil(ind - 1, target, arr, dp);

        boolean taken = false;
        if (arr[ind] <= target) {
            taken = subsetSumUntil(ind - 1, target - arr[ind], arr, dp);
        }

        dp[ind][target] = (nottake || taken) ? 1 : 0;
        return nottake || taken;
    }

    static Boolean isSubsetSum(int arr[], int k) {
        int n = arr.length;
        int[][] dp = new int[n][k + 1];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return subsetSumUntil(n - 1, k, arr, dp);
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 1, 1};
        int k = 4;
        if (isSubsetSum(arr, k))
            System.out.println("Subset with the given target found");
        else
            System.out.println("Subset with the given target not found");
    }
}
