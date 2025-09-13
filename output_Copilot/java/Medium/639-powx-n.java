/**https://leetcode.com/problems/powx-n/ */
//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// 
//Example 1:
//Input: x = 2.00000, n = 10
//Output: 1024.00000
//Example 2:
//Input: x = 2.10000, n = 3
//Output: 9.26100
//Example 3:
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
// 
//Constraints:
//	-100.0 < x < 100.0
//	-231 <= n <= 231-1
//	n is an integer.
//	Either x is not zero or n > 0.
//	-104 <= xn <= 104
class Solution {
    public double myPow(double x, int n) {
        // Handle the case when n is negative
        if (n < 0) {
            x = 1 / x;
            n = -n; // Make n positive
        }
        double result = 1.0;
        while (n > 0) {
            // If n is odd, multiply x with result
            if ((n & 1) == 1) {
                result *= x;
            }
            // Square x and halve n
            x *= x;
            n >>= 1; // Right shift n by 1 (equivalent to dividing by 2)
        }
        return result;        
    }
}