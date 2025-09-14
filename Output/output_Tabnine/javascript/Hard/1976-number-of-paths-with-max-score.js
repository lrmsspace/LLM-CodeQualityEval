/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].
// 
//Example 1:
//Input: board = ["E23","2X2","12S"]
//Output: [7,1]
//Example 2:
//Input: board = ["E12","1X1","21S"]
//Output: [4,2]
//Example 3:
//Input: board = ["E11","XXX","11S"]
//Output: [0,0]
// 
//Constraints:
//	2 <= board.length == board[i].length <= 100
/**
 * @param {string[]} board
 * @return {number[]}
 */
var pathsWithMaxScore = function(board) {
    const MOD = 1e9 + 7;
    const m = board.length;
    const n = board[0].length;
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(10).fill(0)));
    const directions = [[-1, 0], [0, -1], [-1, -1]];
    
    dp[m - 1][n - 1][board[m - 1][n - 1] === 'X'? 0 : parseInt(board[m - 1][n - 1])] = 1;
    
    for (let i = m - 2; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (board[i][j] === 'X') {
                dp[i][j] = [0, 0, 0];
            } else {
                for (const [dx, dy] of directions) {
                    const nx = i + dx;
                    const ny = j + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        const num = parseInt(board[nx][ny]);
                        dp[i][j][num] = (dp[i][j][num] + dp[nx][ny][num + 1]) % MOD;
                    }
                }
            }
        }
    }
    
    let maxScore = 0;
    let count = 0;
    for (let i = 0; i < 10; i++) {
        maxScore = Math.max(maxScore, dp[0][0][i]);
        count = (count + dp[0][0][i]) % MOD;
    }
    
    return [maxScore, count];
    
};