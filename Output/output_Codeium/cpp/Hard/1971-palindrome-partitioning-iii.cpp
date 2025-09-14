/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//	First, change some characters of s to other lowercase English letters.
//	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.
// 
//Example 1:
//Input: s = "abc", k = 2
//Output: 1
//Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
//Example 2:
//Input: s = "aabbc", k = 3
//Output: 0
//Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
//Example 3:
//Input: s = "leetcode", k = 8
//Output: 0
// 
//Constraints:
//	1 <= k <= s.length <= 100.
//	s only contains lowercase English letters.
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size(), res = 0;
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
        for (int i = 0; i < n-k+1; ++i) {
            res += cut[i+k-1];
        }
        return res;
    }
};