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
    // For single digit case
    if (n == 1) {
        for (int i = 9; i >= 1; i--) {
            if (i % k == 0) {
                return to_string(i);
            }
        }
    }
    
    // For multiple digits
    string res;
    int half = (n + 1) / 2;
    
    // Try from largest possible first half
    for (int i = pow(10, half) - 1; i >= pow(10, half-1); i--) {
        string left = to_string(i);
        string right = left;
        reverse(right.begin(), right.end());
        
        if (n % 2 == 1) {
            // For odd length, remove first digit of right half
            right = right.substr(1);
        }
        
        string num = left + right;
        if (stoull(num) % k == 0) {
            return num;
        }
    }
    
    return "";
}            
};