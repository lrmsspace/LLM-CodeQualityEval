/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
/**
 * @param {string} s
 * @return {string}
 */
var smallestSubsequence = function(s) {
    const lastOccurrence = {};
    for (let i = 0; i < s.length; i++) {
        lastOccurrence[s[i]] = i;
    }
    const result = [];
    let start = 0;
    for (let i = 0; i < lastOccurrence.length; i++) {
        let minChar = '';
        let minIndex = Infinity;
        for (const char of Object.keys(lastOccurrence)) {
            if (lastOccurrence[char] < minIndex && lastOccurrence[char] >= start) {
                minChar = char;
                minIndex = lastOccurrence[char];
            }
        }
        result.push(minChar);
        start = minIndex + 1;
        delete lastOccurrence[minChar];
    }
    return result.join('');
};