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
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = k, total = sum[k] - sum[0]; i < n; i++) {
            if (sum[i + 1] - sum[i + 1 - k] > total) {
                total = sum[i + 1] - sum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }
        right[n - k] = n - k;
        for (int i = n - k - 1, total = sum[n] - sum[n - k]; i >= 0; i--) {
            if (sum[i + k] - sum[i] >= total) {
                total = sum[i + k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        int[] res = new int[] { 0, k, 2 * k };
        int max = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = left[i - 1], r = right[i + k];
            int total = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);
            if (total > max) {
                max = total;
                res[0] = l;
                res[1] = i;
                res[2] = r;
            }
        }
        return res;
    }
}