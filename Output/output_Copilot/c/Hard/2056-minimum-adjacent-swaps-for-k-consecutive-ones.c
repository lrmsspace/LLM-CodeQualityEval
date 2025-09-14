/**https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/ */
//You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
//Return the minimum number of moves required so that nums has k consecutive 1's.
// 
//Example 1:
//Input: nums = [1,0,0,1,0,1], k = 2
//Output: 1
//Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
//Example 2:
//Input: nums = [1,0,0,0,0,0,1,1], k = 3
//Output: 5
//Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
//Example 3:
//Input: nums = [1,1,0,1], k = 2
//Output: 0
//Explanation: nums already has 2 consecutive 1's.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is 0 or 1.
//	1 <= k <= sum(nums)
int minMoves(int* nums, int numsSize, int k) {
    int ones[numsSize], cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            ones[cnt++] = i;
        }
    }
    int prefix[cnt + 1];
    prefix[0] = 0;
    for (int i = 1; i <= cnt; i++) {
        prefix[i] = prefix[i - 1] + ones[i - 1];
    }
    int dp[cnt + 1][k + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l <= i; l++) {
                dp[i][j] = fmin(dp[i][j], dp[l][j - 1] + (i - l) * ones[i - 1] - (prefix[i] - prefix[l]));
            }
        }
    }
    int res = INT_MAX;
    for (int i = 1; i <= cnt; i++) {
        res = fmin(res, dp[i][k]);
    }
    return res;  
}