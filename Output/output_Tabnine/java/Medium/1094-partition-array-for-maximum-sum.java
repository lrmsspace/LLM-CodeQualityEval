/**https://leetcode.com/problems/partition-array-for-maximum-sum/ */
//Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: arr = [1,15,7,9,2,5,10], k = 3
//Output: 84
//Explanation: arr becomes [15,15,15,9,10,10,10]
//Example 2:
//Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
//Output: 83
//Example 3:
//Input: arr = [1], k = 1
//Output: 1
// 
//Constraints:
//	1 <= arr.length <= 500
//	0 <= arr[i] <= 109
//	1 <= k <= arr.length
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];
        int[] max = new int[n];
        
        // Initialize max array with first k elements
        for (int i = 0; i < k; i++) {
            max[i] = arr[i];
        }
        
        // Calculate max array up to n-k
        for (int i = k; i < n; i++) {
            max[i] = Math.max(max[i-1], arr[i]);
        }
        
        // Calculate dp array
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = max[i] * (k - i) + (i > 0? dp[i+1] : 0);
        }
        
        // Return the maximum sum from dp array
        return Arrays.stream(dp).max().getAsInt();
        
    }
}