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
int findNumberOfLIS(int* nums, int numsSize){
    int *dp = malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    int *cnt = malloc(sizeof(int) * numsSize);
    memset(cnt, 0, sizeof(int) * numsSize);
    int max_len = 0;
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int cur_len = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (cur_len < dp[j] + 1) {
                    cur_len = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (cur_len == dp[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
        }
    }
    return ans;
}