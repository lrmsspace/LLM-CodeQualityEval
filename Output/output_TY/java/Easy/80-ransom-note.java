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
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] ransom = new int[26];
        int[] mag = new int[26];
        for(int i=0;i<ransomNote.length();i++){
            ransom[ransomNote.charAt(i)-'a']++;
        }
        for(int i=0;i<magazine.length();i++){
            mag[magazine.charAt(i)-'a']++;
        }
        for(int i=0;i<26;i++){
            if(ransom[i]>mag[i]){
                return false;
            }
        }
        return true;
    }
}