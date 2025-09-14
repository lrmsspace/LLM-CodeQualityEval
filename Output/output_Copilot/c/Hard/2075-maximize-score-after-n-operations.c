/**https://leetcode.com/problems/maximize-score-after-n-operations/ */
//You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
//In the ith operation (1-indexed), you will:
//	Choose two elements, x and y.
//	Receive a score of i * gcd(x, y).
//	Remove x and y from nums.
//Return the maximum score you can receive after performing n operations.
//The function gcd(x, y) is the greatest common divisor of x and y.
// 
//Example 1:
//Input: nums = [1,2]
//Output: 1
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 2)) = 1
//Example 2:
//Input: nums = [3,4,6,8]
//Output: 11
//Explanation: The optimal choice of operations is:
//(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
//Example 3:
//Input: nums = [1,2,3,4,5,6]
//Output: 14
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
// 
//Constraints:
//	1 <= n <= 7
//	nums.length == 2 * n
//	1 <= nums[i] <= 106
int maxScore(int* nums, int numsSize) {
    int n = numsSize / 2;
    int dp[1 << n][n];
    memset(dp, 0, sizeof(dp));
    int gcd[n][n];
    memset(gcd, 0, sizeof(gcd));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            gcd[i][j] = __gcd(nums[i], nums[j + n]);
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j)) {
                    dp[mask][i] = fmax(dp[mask][i], dp[mask ^ (1 << i) ^ (1 << j)][j] + (i + 1) * gcd[i][j]);
                }
            }
        }
    }
    return dp[(1 << n) - 1][0];    
}