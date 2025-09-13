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
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let tCount = {};
    for (let c of t) tCount[c] = (tCount[c] || 0) + 1;
    let required = Object.keys(tCount).length;
    let l = 0, r = 0;
    
    let formed = 0;
    windowCounts = {};
    
    let ans = [0, 0, Infinity];
    
    while (r < s.length) {
        character = s[r];
        windowCounts[character] = (windowCounts[character] || 0) + 1;
        
        if (tCount[character] && windowCounts[character] === tCount[character]) formed++;
        
        while (l <= r && formed === required) {
            character = s[l];
            
            if (r - l + 1 < ans[2]) {
                ans[0] = l;
                ans[1] = r;
                ans[2] = r - l + 1;
            }
            
            windowCounts[character] -= 1;
            if (tCount[character] && windowCounts[character] < tCount[character]) formed--;
            
            l++;
        }
        r++;
    }
    return ans[2] === Infinity ? "" : s.substring(ans[0], ans[1] + 1);
};