/**https://leetcode.com/problems/kth-smallest-instructions/ */
//Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.
//The instructions are represented as a string, where each character is either:
//	'H', meaning move horizontally (go right), or
//	'V', meaning move vertically (go down).
//Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
//However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.
//Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.
// 
//Example 1:
//Input: destination = [2,3], k = 1
//Output: "HHHVV"
//Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
//["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
//Example 2:
//Input: destination = [2,3], k = 2
//Output: "HHVHV"
//Example 3:
//Input: destination = [2,3], k = 3
//Output: "HHVVH"
// 
//Constraints:
//	destination.length == 2
//	1 <= row, column <= 15
//	1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.
/**
 * @param {number[]} destination
 * @param {number} k
 * @return {string}
 */
var kthSmallestPath = function(destination, k) {
    const [m, n] = destination;
    const MOD = 1e9 + 7;
    const dp = Array(m + 1).fill(0).map(() => Array(n + 1).fill(0));
    dp[1][1] = 1;
    
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    
    let path = '';
    let [i, j] = [m, n];
    while (i > 1 || j > 1) {
        if (j > 1 && dp[i][j - 1] * k >= dp[i][j]) {
            path += 'H';
            j--;
        } else {
            path += 'V';
            i--;
        }
        k = (k - dp[i][j]) % (dp[i - 1][j] + dp[i][j - 1]);
    }
    return path.split('').reverse().join('');
    
};