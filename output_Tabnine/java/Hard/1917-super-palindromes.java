/**https://leetcode.com/problems/super-palindromes/ */
//Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
// 
//Example 1:
//Input: left = "4", right = "1000"
//Output: 4
//Explanation: 4, 9, 121, and 484 are superpalindromes.
//Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
//Example 2:
//Input: left = "1", right = "2"
//Output: 1
// 
//Constraints:
//	1 <= left.length, right.length <= 18
//	left and right consist of only digits.
//	left and right cannot have leading zeros.
//	left and right represent integers in the range [1, 1018 - 1].
//	left is less than or equal to right.
class Solution {
    public int superpalindromesInRange(String left, String right) {
        int l = left.length(), r = right.length();
        long L = Long.parseLong(left), R = Long.parseLong(right);
        int ans = 0;
        
        // find the smallest and largest palindromes in the range
        long palindromeStart = (long) Math.sqrt(Math.max(L, palindrome(l, r, L)));
        long palindromeEnd = (long) Math.sqrt(R) + 1;
        
        // count the number of palindromes in the range
        for (long palindrome = palindromeStart; palindrome <= palindromeEnd; palindrome++) {
            if (palindrome * palindrome >= L && palindrome * palindrome <= R) {
                ans++;
            }
        }
        
        // count the number of super-palindromes in the range
        for (long i = 1; i <= 9; i++) {
            for (long j = 0; j <= 9; j++) {
                long num = i * 100000000L + j * 1000000L + i * 10000L + j * 1000 + i * 100 + j;
                if (num >= L && num <= R && isPalindrome(num) && num * num >= L && num * num <= R) {
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
}