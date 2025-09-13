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
        // Generate the largest n-digit palindrome divisible by k
        StringBuilder palindrome = new StringBuilder();
        int halfLength = (n + 1) / 2;

        // Start with the largest digit
        for (int i = 0; i < halfLength; i++) {
            palindrome.append(9);
        }

        // Create the full palindrome
        String fullPalindrome = palindrome.toString() + palindrome.reverse().toString().substring(n % 2);

        // Check if it's divisible by k
        long num = Long.parseLong(fullPalindrome);
        while (num % k != 0 && num > 0) {
            num -= 1;
            fullPalindrome = Long.toString(num);
        }

        return fullPalindrome;
    }
}