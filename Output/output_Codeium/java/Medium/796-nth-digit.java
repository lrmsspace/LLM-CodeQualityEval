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
        long start = 1, digitCount = 1, numbersInGroup = 9;
        while (n > digitCount * numbersInGroup) {
            n -= digitCount * numbersInGroup;
            digitCount++;
            numbersInGroup *= 10;
            start *= 10;
        }
        start += (n - 1) / digitCount;
        String s = Long.toString(start);
        return Character.getNumericValue(s.charAt((int)((n - 1) % digitCount)));
    }
}