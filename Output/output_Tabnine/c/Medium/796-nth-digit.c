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
    int digits = 1;
    long count = 9;
    int start = 1;
    
    while (n > count) {
        n -= count;
        digits++;
        count = 9 * (long)Math.pow(10, digits - 1) * digits;
        start *= 10;
    }
    
    int digitIndex = (n - 1) % digits;
    int number = start + (n - 1) / digits;
    return Integer.parseInt(String.valueOf(number).substring(digitIndex, digitIndex + 1));
    
}