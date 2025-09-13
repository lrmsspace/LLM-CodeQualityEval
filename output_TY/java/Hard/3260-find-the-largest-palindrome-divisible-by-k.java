/*
 You are given two positive integers n and k.
 An integer x is called k-palindromic if:
 x is a palindrome.
 x is divisible by k.
 Return the largest integer having n digits (as a string) that is k-palindromic.
 Note that the integer must not have leading zeros.
 Example 1:
 Input: n = 3, k = 5
 Output: "595"
 Explanation:
 595 is the largest k-palindromic integer with 3 digits.
 Example 2:
 Input: n = 1, k = 4
 Output: "8"
 Explanation:
 4 and 8 are the only k-palindromic integers with 1 digit.
 Example 3:
 Input: n = 5, k = 6
 Output: "89898"
 Constraints:
 1 <= n <= 105
 1 <= k <= 9
*/

class Solution {
    public String largestPalindrome(int n, int k) {
        if (n == 1) return "9";
        
        long left = (long) Math.pow(10, n) - 1;
        long right = left / 10;
        
        while (left >= right) {
            long palindrome = left * 10 + right;
            long sqrt = (long) Math.sqrt(palindrome);
            
            if (sqrt * sqrt == palindrome) {
                while (left >= right) {
                    if (palindrome % left == 0) {
                        return Long.toString(palindrome % 1337);
                    }
                    left--;
                }
            }
            right--;
        }
        return "0";
        
    }
}