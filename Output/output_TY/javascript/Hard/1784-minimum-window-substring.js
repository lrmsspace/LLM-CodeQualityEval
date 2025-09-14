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
    let left = 0;
    let right = 0;
    let count = 0;
    let minLength = Infinity;
    let start = 0;
    let map = new Map();
    
    for(let i = 0; i < t.length; i++){
        map.set(t[i], map.get(t[i]) + 1 || 1);
    }
    
    while(right < s.length){
        let char = s[right];
        
        if(map.has(char)){
            map.set(char, map.get(char) - 1);
            
            if(map.get(char) >= 0){
                count++;
            }
        }
    }
    
    while(left <= right && count === t.length){
        if(right - left + 1 < minLength){
            minLength = right - left + 1;
            start = left;
        }
        
        let char = s[left];
        
        if(map.has(char)){
            map.set(char, map.get(char) + 1);
            
            if(map.get(char) > 0){
                count--;
            }
        }
        
        left++;
    }
    
 return minLength === Infinity ? "" : s.slice(start, start + minLength);
};