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
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    if (s1Len > s2Len) {
        return false;
    }

    int* s1Count = (int*)malloc(26 * sizeof(int));
    int* s2Count = (int*)malloc(26 * sizeof(int));
    memset(s1Count, 0, 26 * sizeof(int));
    memset(s2Count, 0, 26 * sizeof(int));

    for (int i = 0; i < s1Len; i++) {
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }

    for (int i = 0; i < s2Len - s1Len + 1; i++) {
        if (memcmp(s1Count, s2Count, 26 * sizeof(int)) == 0) {
            free(s1Count);
            free(s2Count);
            return true;
        }
        s2Count[s2[i] - 'a']--;
        s2Count[s2[i + s1Len] - 'a']++;
    }

    free(s1Count);
    free(s2Count);
    return false;
    
}