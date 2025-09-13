/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        int maxLength = 1;
        int start = 0;
        
        for (int i = 0; i < n - 1; i++) {
            // Check for odd length palindromes
            int len1 = expandAroundCenter(s, i, i);
            
            // Check for even length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Update maxLength and start if necessary
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
        
    }
};