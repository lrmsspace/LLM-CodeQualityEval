/**https://leetcode.com/problems/power-of-three/ */
//Given an integer n, return true if it is a power of three. Otherwise, return false.
//An integer n is a power of three, if there exists an integer x such that n == 3x.
// 
//Example 1:
//Input: n = 27
//Output: true
//Explanation: 27 = 33
//Example 2:
//Input: n = 0
//Output: false
//Explanation: There is no x where 3x = 0.
//Example 3:
//Input: n = -1
//Output: false
//Explanation: There is no x where 3x = (-1).
// 
//Constraints:
//	-231 <= n <= 231 - 1
// 
//Follow up: Could you solve it without loops/recursion?
class Solution {
public:
    bool isPowerOfThree(int n) {
        // if n is less than 1, it can't be a power of 3
        if (n <= 0) return false;
        
        // if n is 1, it is a power of 3
        if (n == 1) return true;
        
        // check if n is a power of 3 by dividing it by 3 repeatedly until it becomes 1
        while (n % 3 == 0) {
            n /= 3;
        }
        
        // if n is not 1 after the division, it can't be a power of 3
        return n == 1;  // 27 is 3^3, so 3^3 is equal to 1 when divided by 3 repeatedly
        
    }
};