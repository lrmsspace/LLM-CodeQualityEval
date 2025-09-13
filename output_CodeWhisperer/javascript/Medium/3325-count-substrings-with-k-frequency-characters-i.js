/*
 Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
 Example 1:
 Input: s = "abacb", k = 2
 Output: 4
 Explanation:
 The valid substrings are:
 "aba" (character 'a' appears 2 times).
 "abac" (character 'a' appears 2 times).
 "abacb" (character 'a' appears 2 times).
 "bacb" (character 'b' appears 2 times).
 Example 2:
 Input: s = "abcde", k = 1
 Output: 15
 Explanation:
 All substrings are valid because every character appears at least once.
 Constraints:
 1 <= s.length <= 3000
 1 <= k <= s.length
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var numberOfSubstrings = function(s, k) {
    let result = 0;
    let charCount = {};
    let left = 0;
    
    for (let right = 0; right < s.length; right++) {
        charCount[s[right]] = (charCount[s[right]] || 0) + 1;
        
        while (Object.values(charCount).every(count => count >= k)) {
            result += s.length - right;
            charCount[s[left]]--;
            left++;
        }
    }
    
    return result;
            
};