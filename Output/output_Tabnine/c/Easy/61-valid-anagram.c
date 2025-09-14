/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//	1 <= s.length, t.length <= 5 * 104
//	s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; t[i]; i++) {
        count[t[i] - 'a']--;
        if (count[t[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}