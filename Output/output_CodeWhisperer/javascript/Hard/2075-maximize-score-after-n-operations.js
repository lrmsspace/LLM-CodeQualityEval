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
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxScore = function(nums) {
    const gcd = (a, b) => {
        if (b === 0) return a;
        return gcd(b, a % b);
    };
    const n = nums.length;
    const dp = new Array(1 << n).fill(0);
    const gcdTemp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            gcdTemp[i][j] = gcd(nums[i], nums[j]);
        }
    }
    let all = 1 << n;
    for (let i = all - 2; i >= 0; i--) {
        let count = 0;
        for (let j = 0; j < n; j++) {
            if ((i >> j) & 1) count++;
        }
        if (count % 2 !== 0) continue;
        for (let j = 0; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                if ((i >> j) & 1 && (i >> k) & 1) {
                    dp[i] = Math.max(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + gcdTemp[j][k] * (count / 2 + 1));
                }
            }
        }
    }
    return dp[all - 1];
};