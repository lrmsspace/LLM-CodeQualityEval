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
    int n = numsSize;
    if (n == 0) return 0;
    int* dp = (int*)malloc(n * sizeof(int));
    int* pre = (int*)malloc(n * sizeof(int));
    int res = 0, maxLen = 1;
    dp[0] = 1;
    pre[0] = -1;
    
    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        pre[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            res = 1;
        } else if (dp[i] == maxLen) {
            res += countPath(pre, i);
        }
    }
    
    free(dp);
    free(pre);
    return res;
    
}