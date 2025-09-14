/**https://leetcode.com/problems/stone-game-iv/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
//Also, if a player cannot make a move, he/she loses the game.
//Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
// 
//Example 1:
//Input: n = 1
//Output: true
//Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
//Example 2:
//Input: n = 2
//Output: false
//Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
//Example 3:
//Input: n = 4
//Output: true
//Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
// 
//Constraints:
//	1 <= n <= 105
/**
 * @param {number} n
 * @return {boolean}
 */
var winnerSquareGame = function(n) {
// Initialize a dp array to store the results for each number up to n
const dp = Array(n + 1).fill(false);

// Iterate through each number from 1 to n
for (let i = 1; i <= n; i++) {
  // Check all square numbers less than or equal to i
  for (let k = 1; k * k <= i; k++) {
    // If there is a move that leaves the opponent in a losing position, mark dp[i] as true
    if (!dp[i - k * k]) {
      dp[i] = true;
      break;
    }
  }
}

// Return the result for n
return dp[n];

};