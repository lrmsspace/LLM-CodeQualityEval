/*
 You are given two strings s and pattern.
 A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
 Return the smallest starting index of a substring in s that is almost equal to pattern. If no such index exists, return -1.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "abcdefg", pattern = "bcdffg"
 Output: 1
 Explanation:
 The substring s[1..6] == "bcdefg" can be converted to "bcdffg" by changing s[4] to "f".
 Example 2:
 Input: s = "ababbababa", pattern = "bacaba"
 Output: 4
 Explanation:
 The substring s[4..9] == "bababa" can be converted to "bacaba" by changing s[6] to "c".
 Example 3:
 Input: s = "abcd", pattern = "dba"
 Output: -1
 Example 4:
 Input: s = "dde", pattern = "d"
 Output: 0
 Constraints:
 1 <= pattern.length < s.length <= 105
 s and pattern consist only of lowercase English letters.
 Follow-up: Could you solve the problem if at most k consecutive characters can be changed?
*/

/**
 * @param {string} s
 * @param {string} pattern
 * @return {number}
 */
var minStartingIndex = function(s, pattern) {
    let patternMap = new Map();
    let patternLength = pattern.length;
    let sLength = s.length;
    
    for (let i = 0; i < patternLength; i++) {
        let char = pattern[i];
        if (patternMap.has(char)) {
            patternMap.get(char).push(i);
        } else {
            patternMap.set(char, [i]);
        }
    }
    
    for (let i = 0; i <= sLength - patternLength; i++) {
        let subString = s.slice(i, i + patternLength);
        let subStringMap = new Map();
        let subStringLength = subString.length;
        
        for (let j = 0; j < subStringLength; j++) {
            let char = subString[j];
            if (subStringMap.has(char)) {
                subStringMap.get(char).push(j);
            } else {
                subStringMap.set(char, [j]);
            }
        }
        
        let isAlmostEqual = true;
        
        for (let [char, indices] of patternMap) {
            if (!subStringMap.has(char)) {
                isAlmostEqual = false;
                break;
            }
            
            let patternIndices = patternMap.get(char);
            let subStringIndices = subStringMap.get(char);
            
            if (patternIndices.length !== subStringIndices.length) {
                isAlmostEqual = false;
                break;
            }
            
            let diffCount = 0;
            
            for (let k = 0; k < patternIndices.length; k++) {
                if (patternIndices[k] !== subStringIndices[k]) {
                    diffCount++;
                }
                
                if (diffCount > 1) {
                    isAlmostEqual = false;
                    break;
                }
            }
            
            if (!isAlmostEqual) {
                break;
            }
        }
        
        if (isAlmostEqual) {
            return i;
        }
    }
    
    return -1;
            
};