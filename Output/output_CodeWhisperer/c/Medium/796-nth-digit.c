/**https://leetcode.com/problems/nth-digit/ */
//Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// 
//Example 1:
//Input: n = 3
//Output: 3
//Example 2:
//Input: n = 11
//Output: 0
//Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
// 
//Constraints:
//	1 <= n <= 231 - 1
int findNthDigit(int n) {
    int i = 1, j = 9, k = 1;
    while (n > (long) i * j) {
        n -= i * j;
        i ++;
        j *= 10;
        k *= 10;
    }
    k += (n - 1) / i;
    return to_string(k)[(n - 1) % i] - '0';
}