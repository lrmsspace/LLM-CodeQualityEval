/**https://leetcode.com/problems/positions-of-large-groups/ */
//In a string s of lowercase letters, these letters form consecutive groups of the same character.
//For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
//A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
//A group is considered large if it has 3 or more characters.
//Return the intervals of every large group sorted in increasing order by start index.
// 
//Example 1:
//Input: s = "abbxxxxzzy"
//Output: [[3,6]]
//Explanation: "xxxx" is the only large group with start index 3 and end index 6.
//Example 2:
//Input: s = "abc"
//Output: []
//Explanation: We have groups "a", "b", and "c", none of which are large groups.
//Example 3:
//Input: s = "abcdddeeeeaabbbcd"
//Output: [[3,5],[6,9],[12,14]]
//Explanation: The large groups are "ddd", "eeee", and "bbb".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s contains lowercase English letters only.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes){
    int i, j, k, n, m, count, start, end;
    int **res;
    n = strlen(s);
    res = (int **)malloc(sizeof(int *) * n);
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        count = 1;
        start = i;
        for (j = i + 1; j < n; j++) {
            if (s[j] == s[i]) {
                count++;
            }
            else {
                break;
            }
        }
    }
    if (count >= 3) {
        res[m] = (int *)malloc(sizeof(int) * 2);
        res[m][0] = start;
        res[m][1] = j - 1;
        m++;
    }
    *returnSize = m;
    return res;
}