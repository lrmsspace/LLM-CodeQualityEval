/**https://leetcode.com/problems/k-concatenation-maximum-sum/ */
//Given an integer array arr and an integer k, modify the array by repeating it k times.
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,2], k = 3
//Output: 9
//Example 2:
//Input: arr = [1,-2,1], k = 5
//Output: 2
//Example 3:
//Input: arr = [-1,-2], k = 7
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= k <= 105
//	-104 <= arr[i] <= 104
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long mod = 1000000007L;
        int n = arr.length;
        long[] prefix = new long[n + 1];
        long[] suffix = new long[n + 1];
        long[] dp = new long[n + 1];
        long maxSum = Long.MIN_VALUE;
        
        // Calculate prefix and suffix sums
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = (prefix[i - 1] + arr[i - 1]) % mod;
        }
        
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] + arr[i]) % mod;
        }
        
        // Calculate dp[i]
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i - 1], prefix[i] + suffix[i - 1]);
            maxSum = Math.max(maxSum, dp[i]);
        }
        
        // Calculate the maximum sub-array sum in the modified array
        long ans = maxSum;
        if (k > 1) {
            ans = (ans * (k - 2) + prefix[n] + suffix[0]) % mod;
        }
        
        return (int) ans;
        
    }
}