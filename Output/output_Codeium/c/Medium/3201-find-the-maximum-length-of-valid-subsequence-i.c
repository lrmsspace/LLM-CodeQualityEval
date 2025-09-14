/*
 You are given an integer array nums.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
 Return the length of the longest valid subsequence of nums.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4].
 Example 2:
 Input: nums = [1,2,1,1,2,1,2]
 Output: 6
 Explanation:
 The longest valid subsequence is [1, 2, 1, 2, 1, 2].
 Example 3:
 Input: nums = [1,3]
 Output: 2
 Explanation:
 The longest valid subsequence is [1, 3].
 Constraints:
 2 <= nums.length <= 2 * 105
 1 <= nums[i] <= 107
*/

int maximumLength(int* nums, int numsSize) {
    int dp[numsSize][2];
    dp[0][0] = dp[0][1] = 1;
    int maxLen = 1;
    for (int i = 1; i < numsSize; ++i) {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; ++j) {
            if ((nums[i] + nums[j]) % 2 == 0) {
                dp[i][0] = fmax(dp[i][0], dp[j][1] + 1);
            } else {
                dp[i][1] = fmax(dp[i][1], dp[j][0] + 1);
            }
            maxLen = fmax(maxLen, fmax(dp[i][0], dp[i][1]));
        }
    }
    return maxLen;
}