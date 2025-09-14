/**https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.
// 
//Example 1:
//Input: nums = [1,3,5,4,7]
//Output: 2
//Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
//Example 2:
//Input: nums = [2,2,2,2,2]
//Output: 5
//Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
// 
//Constraints:
//	1 <= nums.length <= 2000
//	-106 <= nums[i] <= 106
//	The answer is guaranteed to fit inside a 32-bit integer.
int findNumberOfLIS(int* nums, int numsSize) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* count = (int*)malloc(sizeof(int) * numsSize);
    int max = 0;
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        count[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            result = count[i];
        } else if (dp[i] == max) {
            result += count[i];
        }
    }
    free(dp);
    free(count);
    return result;
}