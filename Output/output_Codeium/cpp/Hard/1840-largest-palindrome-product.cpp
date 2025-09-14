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
public:
    int largestPalindrome(int n) {
        int max1 = pow(10, n) - 1;
        int max2 = max1;
        int res = 0;
        for (int i = max1; i > max1 / 10; i--) {
            for (int j = max2; j > max2 / 10; j--) {
                int num = i * j;
                if (num < res) break;
                int rev = 0, temp = num;
                while (temp) {
                    rev = rev * 10 + temp % 10;
                    temp /= 10;
                }
                if (rev == num) {
                    res = max(res, num);
                }
            }
        }
        return res % 1337;
    }
};