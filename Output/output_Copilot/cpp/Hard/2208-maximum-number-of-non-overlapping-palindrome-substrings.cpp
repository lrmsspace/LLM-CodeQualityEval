/**https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/ */
//You are given a string s and a positive integer k.
//Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
//	The length of each substring is at least k.
//	Each substring is a palindrome.
//Return the maximum number of substrings in an optimal selection.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "abaccdbbd", k = 3
//Output: 2
//Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
//It can be shown that we cannot find a selection with more than two valid substrings.
//Example 2:
//Input: s = "adbcda", k = 2
//Output: 0
//Explanation: There is no palindrome substring of length at least 2 in the string.
// 
//Constraints:
//	1 <= k <= s.length <= 2000
//	s consists of lowercase English letters.
class Solution {
public:
    int maxPalindromes(string s, int k) {
            int n = s.size();
            vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
            
            // Precompute palindrome substrings
            for (int len = 1; len <= n; ++len) {
                for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    isPalindrome[i][j] = true;
                } else if (len == 2) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                }
                }
            }
            
            vector<int> dp(n + 1, 0);
            
            // Dynamic programming to find the maximum number of non-overlapping palindromes
            for (int i = 1; i <= n; ++i) {
                dp[i] = dp[i - 1]; // Skip the current character
                for (int j = i - k; j >= 0; --j) {
                if (isPalindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break; // Ensure non-overlapping
                }
                }
            }
            
            return dp[n];
    }   
};