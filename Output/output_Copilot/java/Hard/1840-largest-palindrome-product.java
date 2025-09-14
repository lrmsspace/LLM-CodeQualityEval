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
        if (n == 1) return 9;
        int upper = (int) Math.pow(10, n) - 1;
        int lower = (int) Math.pow(10, n - 1);
        long max = 0;
        for (int i = upper; i >= lower; i--) {
            for (int j = i; j >= lower; j--) {
                long product = (long) i * j;
                if (product <= max) break;
                if (isPalindrome(product)) {
                    max = product;
                    break;
                }
            }
        }
        return (int) (max % 1337);        
    }
}