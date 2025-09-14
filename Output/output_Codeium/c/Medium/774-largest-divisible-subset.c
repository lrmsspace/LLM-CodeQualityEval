/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int maxLen = 0, maxIndex = 0;
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIndex = i;
        }
    }
    *returnSize = maxLen;
    int* ret = (int*)malloc(maxLen * sizeof(int));
    int index = maxLen - 1;
    ret[index--] = nums[maxIndex];
    while (index >= 0) {
        for (int j = maxIndex - 1; j >= 0; j--) {
            if (nums[maxIndex] % nums[j] == 0 && dp[j] == dp[maxIndex] - 1) {
                ret[index--] = nums[j];
                maxIndex = j;
                break;
            }
        }
    }
    return ret;
}