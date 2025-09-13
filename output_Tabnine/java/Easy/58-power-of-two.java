/**https://leetcode.com/problems/power-of-two/ */
//Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
// 
//Example 1:
//Input: n = 1
//Output: true
//Explanation: 20 = 1
//Example 2:
//Input: n = 16
//Output: true
//Explanation: 24 = 16
//Example 3:
//Input: n = 3
//Output: false
// 
//Constraints:
//	-231 <= n <= 231 - 1
// 
//Follow up: Could you solve it without loops/recursion?
class Solution {
    public boolean isPowerOfTwo(int n) {
        // Base case: if n is 0 or 1, return false
        if (n <= 0) {
            return false;
        }
        
        // Check if n is a power of 2 by repeatedly dividing n by 2 until it becomes 1
        while (n % 2 == 0) {
            n /= 2;
        }
        
        // If n is not 1 after dividing by 2, return false
        return n == 1;
        
    }
}