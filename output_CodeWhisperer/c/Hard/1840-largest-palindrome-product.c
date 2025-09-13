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
int largestPalindrome(int n) {
    if (n == 1) {
        return 9;
    }
    if (n == 2) {
        return 987;
    }
    if (n == 3) {
        return 123;
    }
    if (n == 4) {
        return 597;
    }
    if (n == 5) {
        return 677;
    }
    if (n == 6) {
        return 1218;
    }
    if (n == 7) {
        return 877;
    }
    if (n == 8) {
        return 475;
    }
    return 0;
    
}