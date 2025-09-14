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
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
            for (int j = i + 1; j < n; ++j) {
                isPalindrome[i][j] = s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1]);
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                for (int l = 0; l < i - j + 1; ++l) {
                    int r = l + j - 1;
                    if (isPalindrome[l + 1][r - 1]) {
                        dp[i][j] = min(dp[i][j], dp[l][j - 1] + (i - l - 1) * (i - l - 1));
                    }
                }
            }
        }

        return dp[n][k];
        
    }
};