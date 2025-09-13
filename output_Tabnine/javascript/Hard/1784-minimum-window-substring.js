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
    // Count the frequency of each character in t
    let tCount = {};
    for (let char of t) {
        tCount[char] = (tCount[char] || 0) + 1;
    }
    
    // Initialize the variables
    let minLen = Infinity, start = 0, count = 0, charCount = {};
    
    // Iterate through s
    for (let end = 0; end < s.length; end++) {
        let char = s[end];
        
        // If the character is in t, decrement its count in the window
        if (tCount[char]) {
            charCount[char] = (charCount[char] || 0) + 1;
            if (charCount[char] === tCount[char]) {
                count++;
            }
        }
        
        // If all characters in t are in the window, update the minimum window length
        while (count === t.length) {
            // Update the minimum window length if necessary
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
            }
            
            // If the character at the start of the window is in t, increment its count in the window
            let startChar = s[start];
            if (tCount[startChar]) {
                if (charCount[startChar] === tCount[startChar]) {
                    count--;
                }
                charCount[startChar]--;
            }
            
            // Move the start pointer to the right
            start++;
        }
    }
    
    // Return the minimum window substring if found
    return minLen === Infinity? "" : s.substr(start, minLen);
    
};