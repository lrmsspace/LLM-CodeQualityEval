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
    int max = (int) Math.pow(10, n) - 1;
    int min = (int) Math.pow(10, n - 1);
    
    for (int i = max; i >= min; i--) {
        int j = i;
        int rev = 0;
        while (j > 0) {
            rev = rev * 10 + j % 10;
            j /= 10;
        }
        if (rev <= max && rev * i > max * max) {
            return rev * i % 1337;
        }
    }
    
    return 0;
    
}