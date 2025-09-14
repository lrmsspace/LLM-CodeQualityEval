/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        int[] left = new int[n];
        int[] right = new int[n];
        int minSum = Integer.MAX_VALUE;
        for (int i = k; i <= n; i++) {
            int sum = prefixSum[i] - prefixSum[i - k];
            if (sum < minSum) {
                minSum = sum;
                left[i - k] = i - k;
            }
        }
        
        minSum = Integer.MAX_VALUE;
        for (int i = n - k; i >= 0; i--) {
            int sum = prefixSum[i + k] - prefixSum[i];
            if (sum < minSum) {
                minSum = sum;
                right[i] = i + k;
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        int[] result = new int[3];
        for (int i = k; i <= n - 2 * k; i++) {
            int sum = prefixSum[left[i - k]] + prefixSum[i + k] + prefixSum[right[i + 2 * k]];
            if (sum > maxSum) {
                maxSum = sum;
                result[0] = left[i - k];
                result[1] = i;
                result[2] = right[i + 2 * k];
            }
        }
        
        return result;
        
    }
}