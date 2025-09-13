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
        if (t.empty()) return "";
        unordered_map<char, int> t_count, window_count;
        for (char c : t) ++t_count[c];
        
        int have = 0, need = t_count.size();
        int left = 0, right = 0;
        int min_len = INT_MAX, min_start = 0;
        
        while (right < s.length()) {
            char c = s[right];
            ++window_count[c];
            if (t_count.count(c) && window_count[c] == t_count[c]) {
                ++have;
            }
            
            while (have == need) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                
                window_count[s[left]]--;
                if (t_count.count(s[left]) && window_count[s[left]] < t_count[s[left]]) {
                    --have;
                }
                ++left;
            }
            ++right;
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);

    }
};