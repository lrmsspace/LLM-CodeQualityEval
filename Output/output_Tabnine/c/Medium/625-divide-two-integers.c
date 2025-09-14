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
int divide(int dividend, int divisor) {
    // Check for overflow
    long long dividendLong = (long long)dividend;
    long long divisorLong = (long long)divisor;
    if (dividendLong > INT_MAX || divisorLong > INT_MAX || dividendLong < INT_MIN || divisorLong < INT_MIN) {
        return 0;
    }
    
    // Handle negative numbers
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    dividendLong = abs(dividendLong);
    divisorLong = abs(divisorLong);
    
    int quotient = 0;
    while (dividendLong >= divisorLong) {
        long long temp = divisorLong;
        int count = 1;
        while (dividendLong >= (temp << 1)) {
            temp <<= 1;
            count <<= 1;
        }
        dividendLong -= temp;
        quotient += count;
    }
    
    return isNegative? -quotient : quotient;
    
}