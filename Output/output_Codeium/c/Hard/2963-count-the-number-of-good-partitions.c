/*
 You are given a 0-indexed array nums consisting of positive integers.
 A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.
 Return the total number of good partitions of nums.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 8
 Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
 Example 2:
 Input: nums = [1,1,1,1]
 Output: 1
 Explanation: The only possible good partition is: ([1,1,1,1]).
 Example 3:
 Input: nums = [1,2,1,3]
 Output: 2
 Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
*/

#define MOD 1000000007

int numberOfGoodPartitions(int* nums, int numsSize) {
    bool seen[numsSize];
    memset(seen, false, sizeof(seen));
    int dp[numsSize + 1];
    dp[0] = 1;

    for (int i = 1; i <= numsSize; ++i) {
        dp[i] = dp[i - 1];
        int uniqueCount = 0;
        memset(seen, false, sizeof(seen));
        for (int j = i - 1; j >= 0; --j) {
            if (!seen[nums[j]]) {
                seen[nums[j]] = true;
                uniqueCount++;
            }
            if (uniqueCount == i - j) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    return dp[numsSize];
}

