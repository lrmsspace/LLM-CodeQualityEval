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
    const n = board.length;
    const dp = Array.from({ length: n }, () => Array(n).fill([0, 0]));
    dp[n - 1][n - 1] = [0, 1];

    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (board[i][j] === 'X' || (i === n - 1 && j === n - 1)) continue;

            const score = board[i][j] === 'E' ? 0 : Number(board[i][j]);
            let maxScore = -1;
            let paths = 0;

            for (const [di, dj] of [[-1, 0], [0, -1], [-1, -1]]) {
                const ni = i + di;
                const nj = j + dj;

                if (ni >= 0 && nj >= 0) {
                    const [s, p] = dp[ni][nj];
                    if (s > maxScore) {
                        maxScore = s;
                        paths = p;
                    } else if (s === maxScore) {
                        paths += p;
                    }
                }
            }

            if (maxScore !== -1) {
                dp[i][j] = [maxScore + score, paths];
            }
        }
    }

    const result = dp[0][0];
    return result[0] === -1 ? [0, 0] : [result[0], result[1] % (10 ** 9 + 7)];    
};