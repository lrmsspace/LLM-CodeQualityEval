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
        int max = (int)Math.pow(10, n) - 1;
        int min = (int)Math.pow(10, n - 1);
        int res = 0;
        for (int i = max; i >= min; i--) {
            for (int j = i; j >= min; j--) {
                int num = i * j;
                if (num < min * min) {
                    break;
                }
                if (isPalindrome(num)) {
                    res = Math.max(res, num % 1337);
                }
            }
        }
        return res;
    }

    private boolean isPalindrome(int num) {
        String s = String.valueOf(num);
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}