/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.
// 
//Example 1:
//Input: nums = [9,1,2,3,9], k = 3
//Output: 20.00000
//Explanation: 
//The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
//We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
//That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
//Example 2:
//Input: nums = [1,2,3,4,5,6,7], k = 4
//Output: 20.50000
// 
//Constraints:
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 104
//	1 <= k <= nums.length
double largestSumOfAverages(int* nums, int numsSize, int k) {
    
    double dp[numsSize + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    double sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        dp[i + 1][1] = sum / (i + 1);
    }
    for (int i = 2; i <= k; i++) {
        for (int j = i; j <= numsSize; j++) {
            double sum = 0;
            for (int m = j; m >= i; m--) {
                sum += nums[m - 1];
                dp[j][i] = max(dp[j][i], dp[m - 1][i - 1] + sum / (j - m + 1));
            }
        }
    }
    return dp[numsSize][k];
}
