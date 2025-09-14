/**https://leetcode.com/problems/stone-game-ii/ */
//Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
//Alice and Bob take turns, with Alice starting first.
//On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
//The game continues until all the stones have been taken.
//Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
// 
//Example 1:
//Input: piles = [2,7,9,4,4]
//Output: 10
//Explanation:
//	If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
//	If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
//So we return 10 since it's larger.
//Example 2:
//Input: piles = [1,2,3,4,5,100]
//Output: 104
// 
//Constraints:
//	1 <= piles.length <= 100
//	1 <= piles[i] <= 104
/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(piles) {
    const n = piles.length;
    const dp = Array(n).fill(0).map(() => Array(n + 1).fill(0));
    const sum = Array(n).fill(0).map((_, i) => piles[i] + (i < n - 1? sum[i + 1] : 0));
    
    for (let i = n - 1; i >= 0; i--) {
        for (let X = 1; X <= 2 * Math.max(i, n - i - 1); X++) {
            const j = i + X - 1;
            const leftSum = sum[i] - (j < n - 1? sum[j + 1] : 0);
            const rightSum = sum[j + 1] - (i > 0? sum[i - 1] : 0);
            dp[i][X] = Math.max(leftSum - dp[i + 1][Math.min(2 * X, n - i)], rightSum - dp[j + 2][Math.min(2 * (X - 1), n - j - 1)]);
        }
    }
    
    return dp[0][1];
    
};