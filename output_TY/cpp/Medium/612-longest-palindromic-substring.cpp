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
        int maxLen = 1;
        int start = 0;
        int maxStart = 0;
        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
        }
        return s.substr(maxStart, maxLen);
    }
};