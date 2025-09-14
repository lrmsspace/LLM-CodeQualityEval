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
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        vector<int> freq(256, 0);
        for(int i = 0; i < m; i++){
            freq[t[i]]++;
        }
        int i = 0, j = 0;
        int ans = INT_MAX;
        int count = m;
        string res = "";
        while(j < n){
            if(freq[s[j]] > 0){
                count--;
            }
            freq[s[j]]--;
            if(count == 0){
                while(i <= j && freq[s[i]] < 0){
                    freq[s[i]]++;
                    i++;
                }
            }
        }
        if(ans == INT_MAX) return "";
        else return res;
    }
};