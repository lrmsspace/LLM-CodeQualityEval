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
    int* result = (int*)malloc(sizeof(int) * 26);
    int* last = (int*)malloc(sizeof(int) * 26);
    int i, j, k, max, count;
    for (i = 0; i < 26; i++) {
        result[i] = 0;
        last[i] = -1;
    }
    for (i = 0; s[i] != '\0'; i++) {
        last[s[i] - 'a'] = i;
    }
    i = 0;
    while (s[i] != '\0') {
        j = i;
        max = last[s[i] - 'a'];
        while (j <= max) {
            if (last[s[j] - 'a'] > max) {
                max = last[s[j] - 'a'];
            }
            j++;
        }
        result[*returnSize] = max - i + 1;
        (*returnSize)++;
        i = max + 1;
    }
    return result;
}