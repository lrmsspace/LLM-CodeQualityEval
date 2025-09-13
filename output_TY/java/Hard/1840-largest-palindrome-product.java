/**https://leetcode.com/problems/largest-palindrome-product/ */
//Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
// 
//Example 1:
//Input: n = 2
//Output: 987
//Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//Example 2:
//Input: n = 1
//Output: 9
// 
//Constraints:
//	1 <= n <= 8
class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        long upper = (long) Math.pow(10, n) - 1;
        long lower = upper / 10;
        for (long i = upper; i >= lower; i--) {
            long palindrome = i;
            palindrome = palindrome * (long) Math.pow(10, n) + i;
            for (long j = upper; j * j >= palindrome; j--) {
                if (palindrome % j == 0) {
                    return (int) (palindrome % 1337);
                }
            }
        }
        return 0;
    }
}