/**https://leetcode.com/problems/word-pattern/ */
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
//	Each letter in pattern maps to exactly one unique word in s.
//	Each unique word in s maps to exactly one letter in pattern.
//	No two letters map to the same word, and no two words map to the same letter.
// 
//Example 1:
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Explanation:
//The bijection can be established as:
//	'a' maps to "dog".
//	'b' maps to "cat".
//Example 2:
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//Constraints:
//	1 <= pattern.length <= 300
//	pattern contains only lower-case English letters.
//	1 <= s.length <= 3000
//	s contains only lowercase English letters and spaces ' '.
//	s does not contain any leading or trailing spaces.
//	All the words in s are separated by a single space.
/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    let wordMap = new Map();
    let charMap = new Map();
    let words = s.split(' ');
    
    if (pattern.length!== words.length) {
        return false;
    }
    
    for (let i = 0; i < pattern.length; i++) {
        let char = pattern[i];
        let word = words[i];
        
        if (charMap.has(char)) {
            if (charMap.get(char)!== word) {
                return false;
            }
        } else {
            if (wordMap.has(word)) {
                return false;
            }
            charMap.set(char, word);
            wordMap.set(word, char);
        }
    }
    
    return true;
    
};