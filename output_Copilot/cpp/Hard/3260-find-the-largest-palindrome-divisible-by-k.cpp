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
public:
    string largestPalindrome(int n, int k) {
        if (n == 1) {
            return to_string(k * 9 / gcd(k, 9)); // Largest single-digit k-palindrome
        }
        
        string half = string((n + 1) / 2, '9'); // Start with the largest half
        long long num = stoll(half);
        
        while (true) {
            string palindrome = to_string(num);
            if (n % 2 == 0) {
                palindrome += string(palindrome.rbegin(), palindrome.rend());
            } else {
                palindrome += string(palindrome.rbegin() + 1, palindrome.rend());
            }
            
            if (stoll(palindrome) % k == 0) {
                return palindrome;
            }
            num--;
        }
        return ""; // This line should never be reached
        
    }
};