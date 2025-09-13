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
bool isPowerOfFour(int n) {
    // If n is less than or equal to 0, it can't be a power of four
    if (n <= 0) return false;
    
    // Check if n is a power of two
    while (n % 2 == 0) {
        n /= 2;
    }
    
    // If n is not 1 after dividing by 2, it's not a power of four
    return n == 1;
    
}