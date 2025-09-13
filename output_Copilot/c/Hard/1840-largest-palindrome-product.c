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
    if (n == 1) return 9;
    int upper = pow(10, n) - 1, lower = pow(10, n - 1);
    for (int i = upper; i >= lower; i--) {
        long long palindrome = i * pow(10, n) + reverse(i);
        for (long long j = upper; j * j >= palindrome; j--) {
            if (palindrome % j == 0) return palindrome % 1337;
        }
    }
    return -1;    
}