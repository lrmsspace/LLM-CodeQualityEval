/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k != 0) return false;
        int target = sum / k;
        int[] dp = new int[1 << nums.length];
        dp[0] = 0;
        for (int i = 0; i < (1 << nums.length); i++) {
            for (int j = 0; j < nums.length; j++) {
                if ((i & (1 << j)) == 0) continue;
                int pre = dp[i ^ (1 << j)];
                if (pre + nums[j] > target) continue;
                dp[i] = Math.max(dp[i], pre + nums[j]);
            }
        }
        return dp[(1 << nums.length) - 1] == target * k;
    }
}