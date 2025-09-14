/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
//Example 1:
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//Constraints:
//	1 <= s.length, p.length <= 3 * 104
//	s and p consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int* result = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    int pLen = strlen(p);
    int sLen = strlen(s);
    if (pLen > sLen) {
        return result;
    }
    int* pCount = calloc(26, sizeof(int));
    int* sCount = calloc(26, sizeof(int));
    for (int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a']++;
        sCount[s[i] - 'a']++;
    }
    for (int i = 0; i < sLen - pLen + 1; i++) {
        if (memcmp(pCount, sCount, 26 * sizeof(int)) == 0) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
        sCount[s[i] - 'a']--;
        if (i + pLen < sLen) {
            sCount[s[i + pLen] - 'a']++;
        }
    }
    free(pCount);
    free(sCount);
    return result;
}