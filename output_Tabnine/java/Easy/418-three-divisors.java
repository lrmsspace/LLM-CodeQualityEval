/**https://leetcode.com/problems/three-divisors/ */
//Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
//An integer m is a divisor of n if there exists an integer k such that n = k * m.
// 
//Example 1:
//Input: n = 2
//Output: false
//Explantion: 2 has only two divisors: 1 and 2.
//Example 2:
//Input: n = 4
//Output: true
//Explantion: 4 has three divisors: 1, 2, and 4.
// 
//Constraints:
//	1 <= n <= 104
class Solution {
    public boolean isThree(int n) {

        // If n is less than 4, it cannot have three divisors
        if (n < 4) {
            return false;
        }
        
        // Check divisors up to square root of n
        for (int i = 2; i * i <= n; i++) {
            
            // If n is divisible by i, then check if it's divisible by another number
            if (n % i == 0) {
                
                // If n has two divisors, return true
                if (i * i == n) {
                    return true;
                }
                
                // If n has three divisors, return true
                else {
                    return n / i == i;
                }
            }
        }
        
        // If no divisor found, return false
        return false;
        
    }
}