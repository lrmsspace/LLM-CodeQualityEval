/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 500
 1 <= nums[i] <= 109
 0 <= k <= min(nums.length, 25)
*/

int maximumLength(int* nums, int numsSize, int k) {
    int dp[numsSize][k + 1];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l < i; l++) {
                if (nums[i]!= nums[l] && dp[l][j - 1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[l][j - 1] + 1;
                    maxLen = fmax(maxLen, dp[i][j]);
                }
            }
        }
    }
    
    return maxLen;
    
}