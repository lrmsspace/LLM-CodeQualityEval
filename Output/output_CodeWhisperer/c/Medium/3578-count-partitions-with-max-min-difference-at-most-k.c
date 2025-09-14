/*
 You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
 Return the total number of ways to partition nums under this condition.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [9,4,1,3,7], k = 4
 Output: 6
 Explanation:
 There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
 [[9], [4], [1], [3], [7]]
 [[9], [4], [1], [3, 7]]
 [[9], [4], [1, 3], [7]]
 [[9], [4, 1], [3], [7]]
 [[9], [4, 1], [3, 7]]
 [[9], [4, 1, 3], [7]]
 Example 2:
 Input: nums = [3,3,4], k = 0
 Output: 2
 Explanation:
 There are 2 valid partitions that satisfy the given conditions:
 [[3], [3], [4]]
 [[3, 3], [4]]
 Constraints:
 2 <= nums.length <= 5 * 104
 1 <= nums[i] <= 109
 0 <= k <= 109
*/

int countPartitions(int* nums, int numsSize, int k) {
    long long int sum = 0;
    long long int dp[100001] = {0};
    dp[0] = 1;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        for(int j = sum; j >= nums[i]; j--) {
            dp[j] = (dp[j] + dp[j - nums[i]]) % 1000000007;
        }
    }
    long long int res = 0;
    for(int i = 0; i <= sum / 2; i++) {
        if(sum - i - i < k) {
            res = (res + dp[i]) % 1000000007;
        }
    }
    return (int)((2 * res) % 1000000007);
}