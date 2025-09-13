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
bool makesquare(int* matchsticks, int matchsticksSize) {
    int sum = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        sum += matchsticks[i];
    }
    if (sum % 4 != 0) {
        return false;
    }
    int target = sum / 4;
    int* dp = (int*)malloc(sizeof(int) * (1 << matchsticksSize));
    for (int i = 0; i < (1 << matchsticksSize); i++) {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << matchsticksSize); i++) {
        if (dp[i] == -1) {
            continue;
        }
        for (int j = 0; j < matchsticksSize; j++) {
            if ((i & (1 << j)) == 0 && dp[i | (1 << j)] == -1) {
                if (dp[i] + matchsticks[j] <= target) {
                    dp[i | (1 << j)] = (dp[i] + matchsticks[j]) % target;
                }
            }
        }
    }
    bool result = dp[(1 << matchsticksSize) - 1] == 0;
    free(dp);
    return result;
}