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
class Solution {
    public int findNthDigit(int n) {
        int digitCount = 1;
        int start = 1;
        int end = 9;
        
        while (n > digitCount * (end - start + 1)) {
            n -= digitCount * (end - start + 1);
            digitCount++;
            start *= 10;
            end = start * 10 - 1;
        }
        
        int index = n / digitCount;
        int num = start + index - 1;
        int offset = n % digitCount;
        
        return Integer.parseInt(String.valueOf(num).substring(offset, offset + 1));
        
    }
}