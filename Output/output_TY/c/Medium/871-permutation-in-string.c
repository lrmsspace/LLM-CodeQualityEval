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
bool checkInclusion(char * s1, char * s2){
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    if (s1_len > s2_len) return false;
    int s1_hash[26] = {0};
    int s2_hash[26] = {0};
    for (int i = 0; i < s1_len; i++) {
        s1_hash[s1[i] - 'a']++;
        s2_hash[s2[i] - 'a']++;
    }
    for (int i = 0; i <= s2_len -s1_len; i++) {
        if (memcmp(s1_hash, s2_hash, sizeof(int) * 26) == 0) return true; 
    }
    return false;
}