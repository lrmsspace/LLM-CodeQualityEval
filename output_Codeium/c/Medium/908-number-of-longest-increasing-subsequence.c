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
    int dp[numsSize];
    int max = 1;
    int count = 1;
    memset(dp, 1, sizeof(dp));
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] == dp[j] + 1) {
                    count++;
                } else if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count = 1;
                }
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            count = 1;
        }
    }
    return count;
}