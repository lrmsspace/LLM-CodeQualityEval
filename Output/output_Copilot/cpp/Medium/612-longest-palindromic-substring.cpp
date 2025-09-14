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
        if (s.size() < 2) return s;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);        
    }
};