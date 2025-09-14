/**https://leetcode.com/problems/prime-palindrome/ */
//Given an integer n, return the smallest prime palindrome greater than or equal to n.
//An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
//	For example, 2, 3, 5, 7, 11, and 13 are all primes.
//An integer is a palindrome if it reads the same from left to right as it does from right to left.
//	For example, 101 and 12321 are palindromes.
//The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].
// 
//Example 1:
//Input: n = 6
//Output: 7
//Example 2:
//Input: n = 8
//Output: 11
//Example 3:
//Input: n = 13
//Output: 101
// 
//Constraints:
//	1 <= n <= 108
class Solution {
    public int primePalindrome(int n) {
        // Find the largest prime palindrome less than or equal to n
        int left = Math.max(10, n / 10);
        int right = left * 10;
        while (true) {
            int palindrome = reverse(right);
            if (isPrime(palindrome)) {
                return palindrome;
            }
            right++;
        }
        
        // Helper function to reverse an integer
        int reverse(int x) {
            int result = 0;
            while (x!= 0) {
                result = result * 10 + x % 10;
                x /= 10;
            }
            return result;
        }
        
        // Helper function to check if a number is prime
        boolean isPrime(int x) {
            if (x <= 1) {
                return false;
            }
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    return false;
                }
            }
            return true;
        }
        
        // Unreachable code, but required by the problem constraints
        return -1;
        
    }
}