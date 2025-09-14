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
        int[] map = new int[128];
        for (char c : t.toCharArray()) map[c]++;

        int left = 0, right = 0;
        int counter = t.length(), start = 0, end = Integer.MAX_VALUE;
        while (right < s.length()) {
            if (map[s.charAt(right++)]-- > 0) counter--;

            while (counter == 0) {
                if (right - left < end - start) {
                    start = left;
                    end = right;
                }

                if (map[s.charAt(left++)]++ == 0) counter++;

            }
        }   
        return end == 0 ? "" : s.substring(start, end);  
    }
}