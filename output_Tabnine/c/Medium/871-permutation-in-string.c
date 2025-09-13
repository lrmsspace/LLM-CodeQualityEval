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
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2) return false;
    
    int s1_map[26] = {0};
    int s2_map[26] = {0};
    
    for (int i = 0; i < len1; i++) {
        s1_map[s1[i] - 'a']++;
        s2_map[s2[i] - 'a']++;
    }
    
    for (int i = len1; i < len2; i++) {
        if (memcmp(s1_map, s2_map, sizeof(s2_map)) == 0) return true;
        s2_map[s2[i - len1] - 'a']--;
        s2_map[s2[i] - 'a']++;
    }
    
    return memcmp(s1_map, s2_map, sizeof(s2_map)) == 0;
    
}