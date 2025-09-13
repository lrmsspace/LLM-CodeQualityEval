/**https://leetcode.com/problems/minimum-cost-to-merge-stones/ */
//There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
//A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
//Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
// 
//Example 1:
//Input: stones = [3,2,4,1], k = 2
//Output: 20
//Explanation: We start with [3, 2, 4, 1].
//We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
//We merge [4, 1] for a cost of 5, and we are left with [5, 5].
//We merge [5, 5] for a cost of 10, and we are left with [10].
//The total cost was 20, and this is the minimum possible.
//Example 2:
//Input: stones = [3,2,4,1], k = 3
//Output: -1
//Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
//Example 3:
//Input: stones = [3,5,1,2,6], k = 3
//Output: 25
//Explanation: We start with [3, 5, 1, 2, 6].
//We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
//We merge [3, 8, 6] for a cost of 17, and we are left with [17].
//The total cost was 25, and this is the minimum possible.
// 
//Constraints:
//	n == stones.length
//	1 <= n <= 30
//	1 <= stones[i] <= 100
//	2 <= k <= 30
/**
 * @param {number[]} stones
 * @param {number} k
 * @return {number}
 */
var mergeStones = function(stones, k) {
    
    let n = stones.length;
    if ((n - 1) % (k - 1) !== 0) return -1;
    let dp = Array(n).fill().map(() => Array(n).fill().map(() => Array(k).fill(0)));
    let prefixSum = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (j - i + 1 === k) {
                dp[i][j][0] = 0;
            } else {
                dp[i][j][0] = Infinity;
            }
        }
    }
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            for (let m = 1; m < k; m++) {
                for (let l = i; l < j; l++) {
                    dp[i][j][m] = Math.min(dp[i][j][m], dp[i][l][m - 1] + dp[l + 1][j][k - m] + prefixSum[j + 1] - prefixSum[i]);
                }
            }
        }
    }
    return dp[0][n - 1][k];
};