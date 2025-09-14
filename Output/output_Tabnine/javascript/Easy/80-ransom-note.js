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
    const magazineMap = {};
    
    // Count the occurrences of each letter in magazine
    for (let char of magazine) {
        magazineMap[char] = (magazineMap[char] || 0) + 1;
    }
    
    // Check if each letter in ransomNote can be constructed from magazine
    for (let char of ransomNote) {
        if (!magazineMap[char] || magazineMap[char] <= 0) {
            return false;
        }
        magazineMap[char]--;
    }
    
    return true;
    
};