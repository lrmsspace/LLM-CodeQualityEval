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
class Solution {
    public:
        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            // Special cases
            // If the sum of all numbers is less than the target, nobody can win
            int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
            if (sum < desiredTotal) return false;
            
            // If the target is 0 or less, the first player wins immediately
            if (desiredTotal <= 0) return true;
            
            // Use a map to memoize results for different states
            unordered_map<int, bool> memo;
            
            // Start the recursive function with all numbers available (mask = 0)
            return canWin(maxChoosableInteger, desiredTotal, 0, memo);
        }
        
    private:
        bool canWin(int maxNum, int total, int used, unordered_map<int, bool>& memo) {
            // If we've seen this state before, return the cached result
            if (memo.count(used)) return memo[used];
            
            // Try each number that hasn't been used yet
            for (int i = 1; i <= maxNum; i++) {
                int mask = 1 << (i - 1);
                
                // Skip if this number has been used
                if (used & mask) continue;
                
                // If this number is enough to win, or if the opponent can't win after we take this number
                if (i >= total || !canWin(maxNum, total - i, used | mask, memo)) {
                    memo[used] = true;
                    return true;
                }
            }
            
            // If we can't win with any available number
            memo[used] = false;
            return false;
        }
    };
    