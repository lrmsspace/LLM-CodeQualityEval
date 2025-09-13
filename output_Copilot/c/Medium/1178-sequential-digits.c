/**https://leetcode.com/problems/sequential-digits/ */
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
// 
//Example 1:
//Input: low = 100, high = 300
//Output: [123,234]
//Example 2:
//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]
// 
//Constraints:
//	10 <= low <= high <= 10^9
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize) {
    int i, j, k, m, n, t, *ret, *tmp;
    *returnSize = 0;
    ret = (int*)malloc(100 * sizeof(int));
    for (i = 1; i <= 9; i++) {
        t = i;
        for (j = i + 1; j <= 9; j++) {
            t = t * 10 + j;
            if (t >= low && t <= high) {
                ret[(*returnSize)++] = t;
            }
        }
    }
    for (i = 2; i <= 9; i++) {
        t = i;
        for (j = i + 1; j <= 9; j++) {
            t = t * 10 + j;
            if (t >= high) {
                break;
            }
        }
        if (t > high) {
            break;
        }
        tmp = (int*)malloc(100 * sizeof(int));
        m = 0;
        for (k = i + 1; k <= 9; k++) {
            n = t;
            for (j = k; j <= 9; j++) {
                n = n * 10 + j;
                if (n >= low && n <= high) {
                    tmp[m++] = n;
                }
            }
        }
        for (j = 0; j < m; j++) {
            ret[(*returnSize)++] = tmp[j];
        }
        free(tmp);
    }
    return ret;    
}