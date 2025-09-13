/**https://leetcode.com/problems/can-i-win/ */
//In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
//What if we change the game so that players cannot re-use integers?
//For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
//Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
// 
//Example 1:
//Input: maxChoosableInteger = 10, desiredTotal = 11
//Output: false
//Explanation:
//No matter which integer the first player choose, the first player will lose.
//The first player can choose an integer from 1 up to 10.
//If the first player choose 1, the second player can only choose integers from 2 up to 10.
//The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
//Same with other integers chosen by the first player, the second player will always win.
//Example 2:
//Input: maxChoosableInteger = 10, desiredTotal = 0
//Output: true
//Example 3:
//Input: maxChoosableInteger = 10, desiredTotal = 1
//Output: true
// 
//Constraints:
//	1 <= maxChoosableInteger <= 20
//	0 <= desiredTotal <= 300
/**
 * @param {number} maxChoosableInteger
 * @param {number} desiredTotal
 * @return {boolean}
 */
var canIWin = function(maxChoosableInteger, desiredTotal) {
    // If the desired total is more than the maximum sum achievable, the first player can't win
    if (desiredTotal > maxChoosableInteger * (maxChoosableInteger + 1) / 2) return false;
    
    // Create a memoization table to store the result of each subproblem
    const memo = new Map();
    
    // Helper function to determine if the first player can force a win
    function dp(total, remaining) {
        // Check if the result for this subproblem is already calculated
        if (memo.has(total)) return memo.get(total);
        
        // Base case: if the total is equal to or greater than the desired total, the first player wins
        if (total >= desiredTotal) return true;
        
        // Base case: if there are no remaining integers, the first player loses
        if (remaining === 0) return false;
        
        let canWin = false;
        
        // Try all possible integers
        for (let i = 1; i <= maxChoosableInteger; i++) {
            // If the current integer is not chosen, recursively check if the first player can force a win
            if (!remaining.has(i)) {
                remaining.add(i);
                canWin = canWin ||!dp(total + i, remaining);
                remaining.delete(i);
            }
        }
        
        // Store the result in the memoization table
        memo.set(total, canWin);
        
        return canWin;
    }
    
    // Start the game with all integers chosen
    return dp(0, new Set(Array.from({ length: maxChoosableInteger }, (_, i) => i + 1)));
    
};