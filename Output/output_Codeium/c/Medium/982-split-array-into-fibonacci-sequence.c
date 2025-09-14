/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//	0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//	f.length >= 3, and
//	f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
// 
//Example 1:
//Input: num = "1101111"
//Output: [11,0,11,11]
//Explanation: The output [110, 1, 111] would also be accepted.
//Example 2:
//Input: num = "112358130"
//Output: []
//Explanation: The task is impossible.
//Example 3:
//Input: num = "0123"
//Output: []
//Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// 
//Constraints:
//	1 <= num.length <= 200
//	num contains only digits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* splitIntoFibonacci(char* num, int* returnSize) {
    int len = strlen(num);
    int* dp = (int*)malloc(len * sizeof(int));
    dp[0] = num[0] - '0';
    dp[1] = dp[0] * 10 + (num[1] - '0');
    int* result = (int*)malloc(len * sizeof(int));
    int r_size = 0;
    for (int i = 2; i < len; i++) {
        dp[i] = dp[i - 1] * 10 + (num[i] - '0');
        for (int j = i - 2; j >= 0; j--) {
            if (dp[j] + dp[j + 1] == dp[i]) {
                result[r_size++] = dp[i];
                break;
            }
        }
    }
    if (r_size > 0) {
        *returnSize = r_size;
        return result;
    } else {
        free(dp);
        free(result);
        *returnSize = 0;
        return (int*)malloc(0);
    }
}