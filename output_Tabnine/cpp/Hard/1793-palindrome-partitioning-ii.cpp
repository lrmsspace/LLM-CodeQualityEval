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
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);
        
        // Build the table isPalindrome[i][j]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                isPalindrome[i][j] = (s[i] == s[j]) && ((j - i <= 2) || isPalindrome[i + 1][j - 1]);
            }
        }
        
        // Build the dp table
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n - 1];
        
    }
};