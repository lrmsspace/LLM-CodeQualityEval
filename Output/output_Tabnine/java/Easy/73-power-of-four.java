/**https://leetcode.com/problems/power-of-four/ */
//Given an integer n, return true if it is a power of four. Otherwise, return false.
//An integer n is a power of four, if there exists an integer x such that n == 4x.
// 
//Example 1:
//Input: n = 16
//Output: true
//Example 2:
//Input: n = 5
//Output: false
//Example 3:
//Input: n = 1
//Output: true
// 
//Constraints:
//	-231 <= n <= 231 - 1
// 
//Follow up: Could you solve it without loops/recursion?
class Solution {
    public boolean isPowerOfFour(int n) {
        // If the number is less than 1, it's not a power of 4
        if (n < 1) {
            return false;
        }
        
        // Check if the number is a power of 4 by repeatedly dividing it by 4
        while (n % 4 == 0) {
            n /= 4;
        }
        
        // If the number is not 1 after dividing by 4, it's not a power of 4
        return n == 1;
        
    }
}