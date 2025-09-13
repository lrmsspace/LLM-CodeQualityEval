/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) return false;
    int count[26] = {0};
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    if (allZero(count)) return true;
    for (int i = len1; i < len2; i++) {
        count[s2[i] - 'a']--;
        count[s2[i - len1] - 'a']++;
        if (allZero(count)) return true;
    }
    return false;

}