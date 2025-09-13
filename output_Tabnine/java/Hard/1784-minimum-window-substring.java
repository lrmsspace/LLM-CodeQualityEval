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
    public String minWindow(String s, String t) {
        int[] need = new int[256];
        int[] has = new int[256];
        int left = 0, right = 0, minLen = Integer.MAX_VALUE, minStart = 0;
        for (char c : t.toCharArray()) {
            need[c]++;
        }
        int match = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            has[c]++;
            if (need[c] > 0 && has[c] == need[c]) {
                match++;
            }
            while (match == t.length()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char d = s.charAt(left);
                has[d]--;
                if (need[d] > 0 && has[d] < need[d]) {
                    match--;
                }
                left++;
            }
            right++;
        }
        return minLen == Integer.MAX_VALUE? "" : s.substring(minStart, minStart + minLen);
        
    }
}