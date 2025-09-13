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
    public boolean winnerSquareGame(int n) {
        // Create a boolean array dp of size n+1 to store the result of each game
        boolean[] dp = new boolean[n + 1];
        
        // Base cases: when n is 0 or 1, Alice can win immediately
        dp[0] = false;
        dp[1] = false;
        
        // Iterate from 2 to n
        for (int i = 2; i <= n; i++) {
            // Assume Alice loses the game initially
            dp[i] = true;
            
            // Check all possible moves from 1 to sqrt(i)
            for (int j = 1; j * j <= i; j++) {
                // If Bob can win after Alice makes a move, Alice loses the game
                if (!dp[i - j * j]) {
                    dp[i] = false;
                    break;
                }
            }
        }
        
        // Return the result of the game
        return dp[n];
        
    }
}