/**https://leetcode.com/problems/split-array-largest-sum/ */
//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [7,2,5,10,8], k = 2
//Output: 18
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
//Example 2:
//Input: nums = [1,2,3,4,5], k = 2
//Output: 9
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 106
//	1 <= k <= min(50, nums.length)
int splitArray(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        dp[i] = sum;
    }
    for (int i = 1; i < k; i++) {
        for (int j = numsSize - 1; j >= i; j--) {
            int min = INT_MAX;
            for (int m = i - 1; m < j; m++) {
                int val = dp[m] > dp[j - 1] - dp[m] ? dp[m] : dp[j - 1] - dp[m];
                if (val < min) {
                    min = val;
                }
            }
            dp[j] = min;
        }
    }
    int ret = dp[numsSize - 1];
    free(dp);
    return ret;
    
}