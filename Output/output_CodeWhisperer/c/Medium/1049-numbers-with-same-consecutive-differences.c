/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
// 
//Example 1:
//Input: n = 3, k = 7
//Output: [181,292,707,818,929]
//Explanation: Note that 070 is not a valid number, because it has leading zeroes.
//Example 2:
//Input: n = 2, k = 1
//Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
// 
//Constraints:
//	2 <= n <= 9
//	0 <= k <= 9
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numsSameConsecDiff(int n, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    for (int i = 1; i <= 9; i++) {
        int num = i;
        for (int j = 1; j < n; j++) {
            int lastDigit = num % 10;
            if (lastDigit + k <= 9) {
                num = num * 10 + lastDigit + k;
                if (j == n - 1) {
                    result[*returnSize] = num;
                    (*returnSize)++;
                }
            }
            if (lastDigit - k >= 0 && k != 0) {
                num = num * 10 + lastDigit - k;
                if (j == n - 1) {
                    result[*returnSize] = num;
                    (*returnSize)++;
                }
            }
            if (lastDigit + k > 9 && lastDigit - k < 0) {
                break;
            }
        }
        if (k == 0) {
            result[*returnSize] = num;
            (*returnSize)++;
        }
    }
    return result;
}