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
    int n = numsSize;
    double* dp = (double*)malloc(n * k * sizeof(double));
    memset(dp, 0, n * k * sizeof(double));
    
    for (int i = 0; i < n; ++i) {
        dp[i][0] = nums[i];
        for (int j = 1; j < k; ++j) {
            dp[i][j] = nums[i] + dp[i - 1][j - 1];
        }
    }
    
    double* sum = (double*)malloc(n * sizeof(double));
    memset(sum, 0, n * sizeof(double));
    for (int i = 0; i < n; ++i) {
        sum[i] = dp[i][k - 1];
    }
    
    double ans = 0;
    for (int i = k - 1; i < n; ++i) {
        double curSum = sum[i] - sum[i - k + 1];
        double avg = curSum / k;
        ans = fmax(ans, avg + largestSumOfAverages(nums + i - k + 1, n - i - 1, k - 1));
    }
    
    free(dp);
    free(sum);
    
    return ans;
    
}