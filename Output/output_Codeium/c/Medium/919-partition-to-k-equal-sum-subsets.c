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
bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    if (total % k != 0) {
        return false;
    }
    int target = total / k;
    int dp[1 << numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < (1 << numsSize); i++) {
        if (dp[i]) {
            for (int j = 0; j < numsSize; j++) {
                if (!(i & (1 << j))) {
                    int next = i | (1 << j);
                    if (dp[next - (1 << j)] && dp[next - (1 << j)] + nums[j] <= target) {
                        dp[next] = dp[next - (1 << j)] + nums[j];
                    }
                }
            }
        }
    }
    return dp[(1 << numsSize) - 1] == target;
}