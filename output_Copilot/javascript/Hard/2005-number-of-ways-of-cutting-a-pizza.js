/**https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ */
//Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.
// 
//Example 1:
//Input: pizza = ["A..","AAA","..."], k = 3
//Output: 3 
//Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
//Example 2:
//Input: pizza = ["A..","AA.","..."], k = 3
//Output: 1
//Example 3:
//Input: pizza = ["A..","A..","..."], k = 1
//Output: 1
// 
//Constraints:
//	1 <= rows, cols <= 50
//	rows == pizza.length
//	cols == pizza[i].length
//	1 <= k <= 10
//	pizza consists of characters 'A' and '.' only.
/**
 * @param {string[]} pizza
 * @param {number} k
 * @return {number}
 */
var ways = function(pizza, k) {
    const MOD = 1e9 + 7;
    const rows = pizza.length;
    const cols = pizza[0].length;
    
    // Precompute the prefix sum of apples
    const prefix = Array.from({ length: rows + 1 }, () => Array(cols + 1).fill(0));
    
    for (let i = rows - 1; i >= 0; i--) {
        for (let j = cols - 1; j >= 0; j--) {
            prefix[i][j] = (pizza[i][j] === 'A' ? 1 : 0) +
                prefix[i + 1][j] +
                prefix[i][j + 1] -
                prefix[i + 1][j + 1];
        }
    }
    
    // Memoization table
    const memo = Array.from({ length: k }, () => Array.from({ length: rows }, () => Array(cols).fill(-1)));
    
    // Helper function to check if there's at least one apple in the given range
    const hasApple = (r1, c1, r2, c2) => {
        return prefix[r1][c1] - prefix[r2][c1] - prefix[r1][c2] + prefix[r2][c2] > 0;
    };
    
    // Recursive function to count the ways to cut the pizza
    const countWays = (k, r, c) => {
        if (k === 0) return hasApple(r, c, rows, cols) ? 1 : 0;
        if (memo[k][r][c] !== -1) return memo[k][r][c];
        
        let ways = 0;
        
        // Horizontal cuts
        for (let i = r + 1; i < rows; i++) {
            if (hasApple(r, c, i, cols)) {
                ways = (ways + countWays(k - 1, i, c)) % MOD;
            }
        }
        
        // Vertical cuts
        for (let j = c + 1; j < cols; j++) {
            if (hasApple(r, c, rows, j)) {
                ways = (ways + countWays(k - 1, r, j)) % MOD;
            }
        }
        
        memo[k][r][c] = ways;  
        return ways;
    }
    
    return countWays(k - 1, 0, 0);  
};