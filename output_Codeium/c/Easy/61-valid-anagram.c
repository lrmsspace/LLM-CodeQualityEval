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
    int char_count[26] = {0};
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) return false;
    for (int i = 0; i < len_s; ++i) {
        ++char_count[s[i] - 'a'];
        --char_count[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (char_count[i] != 0) return false;
    }
    return true;
}