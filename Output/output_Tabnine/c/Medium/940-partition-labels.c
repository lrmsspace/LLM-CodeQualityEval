/**https://leetcode.com/problems/partition-labels/ */
//You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
//Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
//Return a list of integers representing the size of these parts.
// 
//Example 1:
//Input: s = "ababcbacadefegdehijhklij"
//Output: [9,7,8]
//Explanation:
//The partition is "ababcbaca", "defegde", "hijhklij".
//This is a partition so that each letter appears in at most one part.
//A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
//Example 2:
//Input: s = "eccbbbbdec"
//Output: [10]
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int* res = malloc(sizeof(int) * strlen(s));
    int* last = malloc(sizeof(int) * 26);
    memset(last, -1, sizeof(int) * 26);
    int n = strlen(s);
    int j = 0;
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (last[s[i] - 'a'] > j) {
            j = last[s[i] - 'a'];
        }
        if (i == j) {
            res[start++] = i - j + 1;
        }
    }
    *returnSize = start;
    return res;   
}