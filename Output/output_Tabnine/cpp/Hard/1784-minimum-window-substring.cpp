/**https://leetcode.com/problems/minimum-window-substring/ */
//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//The testcases will be generated such that the answer is unique.
// 
//Example 1:
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
//Example 2:
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
//Example 3:
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//Constraints:
//	m == s.length
//	n == t.length
//	1 <= m, n <= 105
//	s and t consist of uppercase and lowercase English letters.
// 
//Follow up: Could you find an algorithm that runs in O(m + n) time?
class Solution {
public:
    string minWindow(string s, string t) {
        int need[256] = {0}, has[256] = {0};
        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        
        for (char c : t) need[c]++;
        
        while (right < s.length()) {
            if (need[s[right]] > 0) has[s[right]]++;
            if (has[s[right]] == need[s[right]]) {
                while (left <= right && need[s[left]] == 0) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        start = left;
                    }
                    has[s[left]]--;
                    left++;
                }
            }
            right++;
        }
        
        return minLen == INT_MAX? "" : s.substr(start, minLen);
        
    }
};