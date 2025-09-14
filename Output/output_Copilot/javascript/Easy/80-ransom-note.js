/**https://leetcode.com/problems/ransom-note/ */
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
// 
//Example 1:
//Input: ransomNote = "a", magazine = "b"
//Output: false
//Example 2:
//Input: ransomNote = "aa", magazine = "ab"
//Output: false
//Example 3:
//Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
//Constraints:
//	1 <= ransomNote.length, magazine.length <= 105
//	ransomNote and magazine consist of lowercase English letters.
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    const magazineCount = new Array(26).fill(0);
    const ransomNoteCount = new Array(26).fill(0);

    for (const char of magazine) {
        magazineCount[char.charCodeAt() - 'a'.charCodeAt()]++;
    }

    for (const char of ransomNote) {
        ransomNoteCount[char.charCodeAt() - 'a'.charCodeAt()]++;
    }

    for (let i = 0; i < 26; i++) {
        if (ransomNoteCount[i] > magazineCount[i]) {
            return false;
        }
    }

    return true;    
};