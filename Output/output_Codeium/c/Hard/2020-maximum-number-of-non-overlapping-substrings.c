/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//	A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.
// 
//Example 1:
//Input: s = "adefaddaccc"
//Output: ["e","f","ccc"]
//Explanation: The following are all the possible substrings that meet the conditions:
//[
//  "adefaddaccc"
//  "adefadda",
//  "ef",
//  "e",
//  "f",
//  "ccc",
//]
//If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
//Example 2:
//Input: s = "abbaccd"
//Output: ["d","bb","cc"]
//Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** maxNumOfSubstrings(char* s, int* returnSize) {
    int count[26] = {0};
    int start = 0;
    int end = 0;
    int max = 0;
    int max_start = 0;
    int max_end = 0;
    int len = strlen(s);
    while (end < len) {
        count[s[end] - 'a']++;
        if (count[s[end] - 'a'] == 1) {
            start = end;
        }
        while (count[s[end] - 'a'] > 1) {
            count[s[start] - 'a']--;
            start++;
        }
        if (end - start + 1 > max) {
            max = end - start + 1;
            max_start = start;
            max_end = end;
        }
        end++;
    }
    (*returnSize) = (max_end - max_start + 1);
    char** res = (char**)malloc((*returnSize) * sizeof(char*));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = (char*)malloc((max_end - max_start + 2) * sizeof(char));
        strncpy(res[i], s + max_start, max_end - max_start + 1);
        res[i][max_end - max_start + 1] = '\0';
    }
    return res;
}