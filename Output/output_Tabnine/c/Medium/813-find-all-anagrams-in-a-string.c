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
    int* result = malloc(sizeof(int) * (strlen(s) - strlen(p) + 1));
    *returnSize = 0;
    
    int* charCount = calloc(26, sizeof(int));
    int pLen = strlen(p);
    
    for (int i = 0; i < pLen; i++) {
        charCount[p[i] - 'a']++;
    }
    
    int count = 0;
    for (int i = 0; i <= strlen(s) - pLen; i++) {
        if (i == 0) {
            for (int j = 0; j < pLen; j++) {
                charCount[s[j] - 'a']--;
            }
        } else {
            charCount[s[i - 1] - 'a']--;
            charCount[s[i + pLen - 1] - 'a']++;
        }
        
        if (count == 0) {
            for (int j = 0; j < 26; j++) {
                if (charCount[j]!= 0) {
                    count++;
                    break;
                }
            }
        }
        
        if (count == 0) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    
    free(charCount);
    return result;
    
}