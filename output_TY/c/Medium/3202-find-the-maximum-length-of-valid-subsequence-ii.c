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
    int i, j, count, max_len;
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    
    for (i = 0; i < numsSize; i++) {
        count = 0;
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                count = max(count, dp[j]);
            }
        }
        dp[i] = count + 1;
        max_len = max(max_len, dp[i]);
    }
    return max_len;

    
}