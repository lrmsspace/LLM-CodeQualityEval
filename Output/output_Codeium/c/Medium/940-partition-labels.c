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
    
    int last[26], start = 0, end = 0, index = 0;
    for (int i = 0; s[i]; i++) {
        last[s[i] - 'a'] = i;
    }
    int* result = (int*)malloc(sizeof(int) * 500);
    while (s[index]) {
        end = last[s[index] - 'a'];
        for (int i = start; i < end; i++) {
            if (last[s[i] - 'a'] > end) {
                end = last[s[i] - 'a'];
            }
        }
        result[*returnSize] = end - start + 1;
        (*returnSize)++;
        start = end + 1;
        index = start;
    }
    return result;
}
