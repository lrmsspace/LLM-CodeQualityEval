/*
 You are given an array nums consisting of integers. You are also given a 2D array queries, where queries[i] = [posi, xi].
 For query i, we first set nums[posi] equal to xi, then we calculate the answer to query i which is the maximum sum of a subsequence of nums where no two adjacent elements are selected.
 Return the sum of the answers to all queries.
 Since the final answer may be very large, return it modulo 109 + 7.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]
 Output: 21
 Explanation:
 After the 1st query, nums = [3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 3 + 9 = 12.
 After the 2nd query, nums = [-3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 9.
 Example 2:
 Input: nums = [0,-1], queries = [[0,-5]]
 Output: 0
 Explanation:
 After the 1st query, nums = [-5,-1] and the maximum sum of a subsequence with non-adjacent elements is 0 (choosing an empty subsequence).
 Constraints:
 1 <= nums.length <= 5 * 104
 -105 <= nums[i] <= 105
 1 <= queries.length <= 5 * 104
 queries[i] == [posi, xi]
 0 <= posi <= nums.length - 1
 -105 <= xi <= 105
*/

int maximumSumSubsequence(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int MOD = 1e9 + 7;
    int* dp = (int*)calloc(numsSize, sizeof(int));
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);
    
    for (int i = 2; i < numsSize; i++) {
        dp[i] = fmax(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int* dp2 = (int*)calloc(numsSize, sizeof(int));
    dp2[numsSize - 1] = nums[numsSize - 1];
    dp2[numsSize - 2] = fmax(nums[numsSize - 1], nums[numsSize - 2]);   
    for (int i = numsSize - 3; i >= 0; i--) {
        dp2[i] = fmax(dp2[i + 1], dp2[i + 2] + nums[i]);
    }
    int sum = 0;
    for (int i = 0; i < queriesSize; i++) {
        int pos = queries[i][0];
        int val = queries[i][1];
        nums[pos] = val;
        if (pos == 0) {
            sum = (sum + dp[pos]) % MOD;
        } else if (pos == numsSize - 1) {
            sum = (sum + dp2[pos]) % MOD;
        } else {
            sum = (sum + dp[pos] + dp2[pos]) % MOD;
        }
    }
    free(dp);
    free(dp2);
    return sum;
    
}