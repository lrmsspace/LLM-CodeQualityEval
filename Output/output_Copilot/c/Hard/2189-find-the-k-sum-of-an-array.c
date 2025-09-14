/**https://leetcode.com/problems/find-the-k-sum-of-an-array/ */
//You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
//We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
//Return the K-Sum of the array.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//Note that the empty subsequence is considered to have a sum of 0.
// 
//Example 1:
//Input: nums = [2,4,-2], k = 5
//Output: 2
//Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
//- 6, 4, 4, 2, 2, 0, 0, -2.
//The 5-Sum of the array is 2.
//Example 2:
//Input: nums = [1,-2,3,4,-10,12], k = 16
//Output: 10
//Explanation: The 16-Sum of the array is 10.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	-109 <= nums[i] <= 109
//	1 <= k <= min(2000, 2n)
long long kSum(int* nums, int numsSize, int k) {
    long long sum = 0;
    int i;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            sum += nums[i];
        }
    }
    if(sum == 0) {
        return 0;
    }
    long long dp[2][sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int j;
    for(i = 0; i < numsSize; i++) {
        for(j = 0; j <= sum; j++) {
            dp[(i + 1) % 2][j] = dp[i % 2][j];
            if(j >= nums[i]) {
                dp[(i + 1) % 2][j] += dp[i % 2][j - nums[i]];
            }
        }
    }
    for(i = sum; i >= 0; i--) {
        if(dp[numsSize % 2][i] >= k) {
            return i;
        }
    }
    return 0;    
}