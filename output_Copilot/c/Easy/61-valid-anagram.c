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
    int s_len = strlen(s);
    int t_len = strlen(t);
    if(s_len != t_len) return false;
    int s_count[26] = {0};
    int t_count[26] = {0};
    for(int i = 0; i < s_len; i++) {
        s_count[s[i] - 'a']++;
        t_count[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(s_count[i] != t_count[i]) return false;
    }
    return true;    
}