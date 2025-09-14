/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j-i<2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }
        vector<int> cut(n, n-1);
        for (int i = 0; i < n; ++i) {
            if (dp[0][i]) {
                cut[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (dp[j+1][i] && cut[j] + 1 < cut[i]) {
                        cut[i] = cut[j] + 1;
                    }
                }
            }
        }
        return cut[n-1];
    }
};