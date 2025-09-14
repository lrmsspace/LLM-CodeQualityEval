/*
 You are given a string target, an array of strings words, and an integer array costs, both arrays of the same length.
 Imagine an empty string s.
 You can perform the following operation any number of times (including zero):
 Choose an index i in the range [0, words.length - 1].
 Append words[i] to s.
 The cost of operation is costs[i].
 Return the minimum cost to make s equal to target. If it's not possible, return -1.
 Example 1:
 Input: target = "abcdef", words = ["abdef","abc","d","def","ef"], costs = [100,1,1,10,5]
 Output: 7
 Explanation:
 The minimum cost can be achieved by performing the following operations:
 Select index 1 and append "abc" to s at a cost of 1, resulting in s = "abc".
 Select index 2 and append "d" to s at a cost of 1, resulting in s = "abcd".
 Select index 4 and append "ef" to s at a cost of 5, resulting in s = "abcdef".
 Example 2:
 Input: target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]
 Output: -1
 Explanation:
 It is impossible to make s equal to target, so we return -1.
 Constraints:
 1 <= target.length <= 5 * 104
 1 <= words.length == costs.length <= 5 * 104
 1 <= words[i].length <= target.length
 The total sum of words[i].length is less than or equal to 5 * 104.
 target and words[i] consist only of lowercase English letters.
 1 <= costs[i] <= 104
*/

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        int m = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(26, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = words[j].size();
                if (i + len <= n) {
                    int cost = 0;
                    for (int k = 0; k < len; k++) {
                        if (target[i + k] != words[j][k]) {
                            cost += costs[j];
                            break;
                        }
                    }
                    for (int k = 0; k < 26; k++) {
                        if (dp[i][k] != INT_MAX) {
                            dp[i + len][k] = min(dp[i + len][k], dp[i][k] + cost);
                        }
                    }
                }
            }
            for (int j = 0; j < 26; j++) {
                if (dp[i][j] != INT_MAX) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans == INT_MAX ? -1 : ans;

    }
};