/*
 You are given an integer array nums and two integers, k and m.
 Return the maximum sum of k non-overlapping subarrays of nums, where each subarray has a length of at least m.
 Example 1:
 Input: nums = [1,2,-1,3,3,4], k = 2, m = 2
 Output: 13
 Explanation:
 The optimal choice is:
 Subarray nums[3..5] with sum 3 + 3 + 4 = 10 (length is 3 >= m).
 Subarray nums[0..1] with sum 1 + 2 = 3 (length is 2 >= m).
 The total sum is 10 + 3 = 13.
 Example 2:
 Input: nums = [-10,3,-1,-2], k = 4, m = 1
 Output: -10
 Explanation:
 The optimal choice is choosing each element as a subarray. The output is (-10) + 3 + (-1) + (-2) = -10.
 Constraints:
 1 <= nums.length <= 2000
 -104 <= nums[i] <= 104
 1 <= k <= floor(nums.length / m)
 1 <= m <= 3
*/

int maxSum(int* nums, int numsSize, int k, int m) {

    int dp[k][numsSize];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= m) {
                dp[j][i] = nums[i] + max(dp[j][i-1], dp[j][i-m]);
            } else {
                dp[j][i] = nums[i];
            }
        }
    }
    
    int maxSum = INT_MIN;
    for (int i = 0; i < k; i++) {
        maxSum = max(maxSum, dp[i][numsSize-1]);
    }
    
    return maxSum;
    
}