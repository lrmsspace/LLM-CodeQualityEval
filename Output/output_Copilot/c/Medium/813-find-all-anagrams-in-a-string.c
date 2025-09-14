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
    int sLen = strlen(s);
    int pLen = strlen(p);
    int* res = (int*)malloc(sizeof(int) * sLen);
    int* hash = (int*)malloc(sizeof(int) * 26);
    memset(hash, 0, sizeof(int) * 26);
    for (int i = 0; i < pLen; i++) {
        hash[p[i] - 'a']++;
    }
    int left = 0, right = 0, count = pLen;
    while (right < sLen) {
        if (hash[s[right] - 'a'] > 0) {
            count--;
        }
        hash[s[right] - 'a']--;
        right++;
        if (count == 0) {
            res[(*returnSize)++] = left;
        }
        if (right - left == pLen) {
            if (hash[s[left] - 'a'] >= 0) {
                count++;
            }
            hash[s[left] - 'a']++;
            left++;
        }
    }
    return res;    
}