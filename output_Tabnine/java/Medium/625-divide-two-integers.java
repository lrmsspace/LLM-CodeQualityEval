/**https://leetcode.com/problems/divide-two-integers/ */
//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
//Return the quotient after dividing dividend by divisor.
//Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
// 
//Example 1:
//Input: dividend = 10, divisor = 3
//Output: 3
//Explanation: 10/3 = 3.33333.. which is truncated to 3.
//Example 2:
//Input: dividend = 7, divisor = -3
//Output: -2
//Explanation: 7/-3 = -2.33333.. which is truncated to -2.
// 
//Constraints:
//	-231 <= dividend, divisor <= 231 - 1
//	divisor != 0
class Solution {
    public int divide(int dividend, int divisor) {
        // Check for edge cases
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if (dividend == Integer.MIN_VALUE && divisor == 1) {
            return Integer.MIN_VALUE;
        }
        if (dividend == 0) {
            return 0;
        }
        
        // Determine the sign of the result
        int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)? 1 : -1;
        
        // Convert the dividend and divisor to positive
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        
        // Initialize the quotient
        int quotient = 0;
        
        // Perform the division
        while (dividend >= divisor) {
            int temp = divisor;
            int count = 1;
            
            // Double the divisor until it is greater than the dividend
            while (dividend >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            
            // Subtract the doubled divisor from the dividend and add the count to the quotient
            dividend -= temp;
            quotient += count;
        }
        
        // Apply the sign to the quotient
        return sign * quotient;
        
    }
}