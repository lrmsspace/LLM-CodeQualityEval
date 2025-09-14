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
    int* result = (int*)malloc(sizeof(int) * 300);
    *returnSize = 0;
    int num_len = strlen(num);
    for (int i = 1; i <= num_len - 2; i++) {
        for (int j = i + 1; j <= num_len - 1; j++) {
            int a = 0, b = 0, c = 0;
            for (int k = 0; k < i; k++) {
                a = a * 10 + (num[k] - '0');
            }
            for (int k = i; k < j; k++) {
                b = b * 10 + (num[k] - '0');
            }
            for (int k = j; k < num_len; k++) {
                c = c * 10 + (num[k] - '0');
            }
            if (a > 2147483647 || b > 2147483647 || c > 2147483647) {
                continue;
            }
            if (a + b == c) {
                result[(*returnSize)++] = a;
                result[(*returnSize)++] = b;
                result[(*returnSize)++] = c;
                return result;
            }
            if (a + b < c) {
                break;
            }
        }
    }
    *returnSize = 0;
    return result;
}