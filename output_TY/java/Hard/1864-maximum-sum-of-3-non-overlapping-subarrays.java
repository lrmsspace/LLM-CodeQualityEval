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
        int[] left = new int[n], right = new int[n], ans = new int[3];
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i];
        left[k - 1] = sum;
        for(int i = k; i < n; i++){
            sum += nums[i] - nums[i - k];
            left[i] = Math.max(left[i - 1], sum);
        }
        sum = 0;
        for(int i = n - 1; i >= n - k; i--)
            sum += nums[i];
            right[n - k] = sum;
            for(int i = n - k - 1; i >= 0; i--){
                sum += nums[i] - nums[i + k];
                right[i] = Math.max(right[i + 1], sum);
            }
            for(int i = 0; i < n - k; i++)
                if(left[i] + right[i + k] > max)
                    max = left[i] + right[i + k];
                    return max;
    }
}