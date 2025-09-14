/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
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
int* findAnagrams(char * s, char * p, int* returnSize){
    int sLen = strlen(s), pLen = strlen(p);
    if (sLen < pLen) {
        *returnSize = 0;
        return NULL;
    }
    int *sHash = (int *)malloc(26 * sizeof(int));
    memset(sHash, 0, 26 * sizeof(int));
    for (int i = 0; i < pLen; i++) {
        sHash[p[i] - 'a']++;
    }
    int *sHash2 = (int *)malloc(26 * sizeof(int));
    memset(sHash2, 0, 26 * sizeof(int));
    int left = 0, right = 0;
    while (right < sLen) {
        sHash2[s[right] - 'a']++;
        if (right - left + 1 == pLen) {
            if (memcmp(sHash, sHash2, 26 * sizeof(int)) == 0) {
                ans[*returnSize] = left;
                *returnSize += 1;
            }
            sHash2[s[left] - 'a']--;
        }
    }
    return ans;
}