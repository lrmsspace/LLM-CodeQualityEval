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
    const int MOD = 1000000007;
    std::vector<long long> dp(numsSize + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= numsSize; i++) {
        long long maxVal = nums[i - 1], minVal = nums[i - 1];
        for (int j = i - 1; j >= 0; j--) {
            maxVal = std::max(maxVal, (long long)nums[j]);
            minVal = std::min(minVal, (long long)nums[j]);
            if (maxVal - minVal > k) break;
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    return dp[numsSize];
}