/*
 You are given a string s consisting of lowercase English letters.
 Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
 a1 has an odd frequency in the string.
 a2 has an even frequency in the string.
 Return this maximum difference.
 Example 1:
 Input: s = "aaaaabbc"
 Output: 3
 Explanation:
 The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
 The maximum difference is 5 - 2 = 3.
 Example 2:
 Input: s = "abcabcab"
 Output: 1
 Explanation:
 The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
 The maximum difference is 3 - 2 = 1.
 Constraints:
 3 <= s.length <= 100
 s consists only of lowercase English letters.
 s contains at least one character with an odd frequency and one with an even frequency.
*/

/**
 * @param {string} s
 * @return {number}
 */
var maxDifference = function(s) {
    let freq = new Map();
    for (let char of s) {
        freq.set(char, (freq.get(char) || 0) + 1);
    }
    
    let oddChar = null;
    let evenChar = null;
    let maxDiff = 0;
    
    for (let [char, count] of freq) {
        if (count % 2 === 1) {
            oddChar = char;
        } else {
            evenChar = char;
        }
        
        if (oddChar && evenChar) {
            maxDiff = Math.max(maxDiff, Math.abs(freq.get(oddChar) - freq.get(evenChar)));
        }
    }
    
    return maxDiff;
    
};