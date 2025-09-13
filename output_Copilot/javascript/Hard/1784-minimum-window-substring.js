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
    let map = new Map();
    let left = 0;
    let right = 0;
    let minLength = Infinity;
    let minSubstring = "";
    let count = t.length;

    for (let char of t) {
        map.set(char, (map.get(char) || 0) + 1);
    }

    while (right < s.length) {
        if (map.has(s[right])) {
            if (map.get(s[right]) > 0) {
                count--;
            }
            map.set(s[right], map.get(s[right]) - 1);
        }
        right++;

        while (count === 0) {
            if (right - left < minLength) {
                minLength = right - left;
                minSubstring = s.substring(left, right);
            }

            if (map.has(s[left])) {
                if (map.get(s[left]) === 0) {
                    count++;
                }
                map.set(s[left], map.get(s[left]) + 1);
            }
            left++;
        }
    }

    return minSubstring;    
};