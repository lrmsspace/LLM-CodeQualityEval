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
class Solution {
public:
    bool winnerSquareGame(int n) {
        
        // Initialize a vector to store the result of each n
        vector<bool> dp(n + 1, false);
        
        // The game ends when n is 0 or 1
        dp[0] = false;
        dp[1] = false;
        
        // Calculate the result for each n from 2 to n
        for (int i = 2; i <= n; i++) {
            // Assume Bob can win the game
            bool canBobWin = true;
            
            // Try to remove a square number of stones from i
            for (int j = 1; j * j <= i; j++) {
                // If Bob can win the game after removing j stones, then Alice cannot win
                if (dp[i - j * j]) {
                    canBobWin = false;
                    break;
                }
            }
            
            // Update the result for i
            dp[i] = canBobWin;
        }
        
        // Return the result for n
        return dp[n];
    }
};