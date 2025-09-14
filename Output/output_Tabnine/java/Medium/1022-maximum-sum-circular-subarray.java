/**https://leetcode.com/problems/maximum-sum-circular-subarray/ */
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
// 
//Example 1:
//Input: nums = [1,-2,3,-2]
//Output: 3
//Explanation: Subarray [3] has maximum sum 3.
//Example 2:
//Input: nums = [5,-3,5]
//Output: 10
//Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
//Example 3:
//Input: nums = [-3,-2,-3]
//Output: -2
//Explanation: Subarray [-2] has maximum sum -2.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 3 * 104
//	-3 * 104 <= nums[i] <= 3 * 104
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        int[] suffixSum = new int[n + 1];
        int[] prefixMaxSum = new int[n + 1];
        int[] prefixMinSum = new int[n + 1];
        int[] suffixMaxSum = new int[n + 1];
        int[] suffixMinSum = new int[n + 1];
        
        prefixSum[0] = 0;
        suffixSum[n] = 0;
        
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            suffixSum[n - i + 1] = suffixSum[n - i + 2] + nums[n - i];
        }
        
        int maxSum = Integer.MIN_VALUE;
        
        for (int i = 1; i <= n; i++) {
            prefixMaxSum[i] = Math.max(prefixMaxSum[i - 1], prefixSum[i]);
            prefixMinSum[i] = Math.min(prefixMinSum[i - 1], prefixSum[i]);
            suffixMaxSum[n - i + 1] = Math.max(suffixMaxSum[n - i + 2], suffixSum[n - i + 1]);
            suffixMinSum[n - i + 1] = Math.min(suffixMinSum[n - i + 2], suffixSum[n - i + 1]);
            
            maxSum = Math.max(maxSum, prefixMaxSum[i] + suffixMinSum[i]);
            maxSum = Math.max(maxSum, prefixMinSum[i] + suffixMaxSum[i]);
        }
        
        return maxSum;
        
    }
}