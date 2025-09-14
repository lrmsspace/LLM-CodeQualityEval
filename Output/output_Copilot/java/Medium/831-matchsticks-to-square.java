/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.
// 
//Example 1:
//Input: matchsticks = [1,1,2,2,2]
//Output: true
//Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//Example 2:
//Input: matchsticks = [3,3,3,3,4]
//Output: false
//Explanation: You cannot find a way to form a square with all the matchsticks.
// 
//Constraints:
//	1 <= matchsticks.length <= 15
//	1 <= matchsticks[i] <= 108
class Solution {
    public boolean makesquare(int[] matchsticks) {
        int sum = 0;
        for (int matchstick : matchsticks) {
            sum += matchstick;
        }
        if (sum % 4 != 0) return false;
        int side = sum / 4;
        Arrays.sort(matchsticks);
        return dfs(matchsticks, matchsticks.length - 1, new int[4], side);      
        
        }

        private boolean dfs(int[] matchsticks, int index, int[] sides, int target) {
            if (index < 0) {
                return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
            }
            for (int i = 0; i < 4; i++) {
                if (sides[i] + matchsticks[index] > target) continue;
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, index - 1, sides, target)) return true;
                sides[i] -= matchsticks[index];
                if (sides[i] == 0) break; // Optimization: avoid redundant work
            }
            return false;
        }
        
}   