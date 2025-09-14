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
        if (n < 2) return false; // 1 has only one divisor
        int count = 0;
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                count++;
                if (i != n / i) count++; // Count the complementary divisor
            }
            if (count > 3) return false; // Early exit if more than 3 divisors found
        }
        return count == 3; // Check if exactly 3 divisors found        
    }
}