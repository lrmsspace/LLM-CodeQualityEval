/*
 You are given an integer array nums and a positive integer k.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 Return the length of the longest valid subsequence of nums.
 Example 1:
 Input: nums = [1,2,3,4,5], k = 2
 Output: 5
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4, 5].
 Example 2:
 Input: nums = [1,4,2,3,1,4], k = 3
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 4, 1, 4].
 Constraints:
 2 <= nums.length <= 103
 1 <= nums[i] <= 107
 1 <= k <= 103
*/

int maximumLength(int* nums, int numsSize, int k) {
    int dp[numsSize][k];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 1; j < k; j++) {
            if (nums[i] % j == 0) {
                dp[i][j] = dp[i - 1][(nums[i] / j) % k] + 1;
                maxLen = fmax(maxLen, dp[i][j]);
            }
        }
    }
    
    return maxLen;
    
}