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
        int m = s.size(), n = t.size();
        if (m < n) return "";
        vector<int> cnt(128, 0);
        for (int i = 0; i < n; i++) {
            cnt[t[i]]++;
        }
        int left = 0, right = 0, minLen = INT_MAX, minLeft = 0;
        while (right < m) {
            if (cnt[s[right]] > 0) {
                n--;
            }
            cnt[s[right]]--;
            right++;
            while (n == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minLeft = left;
                }
                if (cnt[s[left]] == 0) {
                    n++;
                }
                cnt[s[left]]++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);    
    }
};