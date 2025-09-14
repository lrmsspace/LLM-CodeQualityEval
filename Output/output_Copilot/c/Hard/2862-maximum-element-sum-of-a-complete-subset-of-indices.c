/*
 You are given a 1-indexed array nums. Your task is to select a complete subset from nums where every pair of selected indices multiplied is a perfect square,. i. e. if you select ai and aj, i * j must be a perfect square.
 Return the sum of the complete subset with the maximum sum.
 Example 1:
 Input: nums = [8,7,3,5,7,2,4,9]
 Output: 16
 Explanation:
 We select elements at indices 2 and 8 and 2 * 8 is a perfect square.
 Example 2:
 Input: nums = [8,10,3,8,1,13,7,9,4]
 Output: 20
 Explanation:
 We select elements at indices 1, 4, and 9. 1 * 4, 1 * 9, 4 * 9 are perfect squares.
 Constraints:
 1 <= n == nums.length <= 104
 1 <= nums[i] <= 109
*/

long long maximumSum(int* nums, int numsSize) {
    long long dp[100001] = {0};
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = i + 1;
        for (int j = 1; j * j <= idx; j++) {
            if (idx % j == 0) {
                dp[idx] = dp[idx / j] + nums[i];
                ans = ans > dp[idx] ? ans : dp[idx];
                if (j * j != idx) {
                    dp[idx] = dp[j] + nums[i];
                    ans = ans > dp[idx] ? ans : dp[idx];
                }
            }
        }
    }

    return ans;    
}