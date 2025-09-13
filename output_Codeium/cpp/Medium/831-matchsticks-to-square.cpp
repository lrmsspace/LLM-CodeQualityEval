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
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int len : matchsticks) {
            sum += len;
        }
        if (sum % 4 != 0) {
            return false;
        }
        int side = sum / 4;
        vector<int> dp(1 << matchsticks.size(), 0);
        dp[0] = 0;
        for (int i = 0; i < (1 << matchsticks.size()); ++i) {
            if (dp[i] >= 0) {
                for (int j = 0; j < matchsticks.size(); ++j) {
                    if (i & (1 << j)) {
                        continue;
                    }
                    int next = dp[i] + matchsticks[j];
                    if (next > side) {
                        dp[i | (1 << j)] = -1;
                    } else if (next == side) {
                        dp[i | (1 << j)] = 0;
                    } else {
                        dp[i | (1 << j)] = next;
                    }
                }
            }
        }
        return dp[(1 << matchsticks.size()) - 1] == 0;
        }
};