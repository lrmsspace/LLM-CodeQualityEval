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
bool canConstruct(char* ransomNote, char* magazine) {
    int ransomNoteLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);
    if (ransomNoteLen > magazineLen) {
        return false;
    }
    int ransomNoteCount[26] = {0};
    int magazineCount[26] = {0};
    for (int i = 0; i < ransomNoteLen; i++) {
        ransomNoteCount[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < magazineLen; i++) {
        magazineCount[magazine[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (ransomNoteCount[i] > magazineCount[i]) {
            return false;
        }
    }
    return true;    
}