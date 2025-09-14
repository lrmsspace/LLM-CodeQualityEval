/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
class Solution {
    public String nearestPalindromic(String n) {
        long n1 = Long.parseLong(n);
        long n2 = n1 - 1;
        long n3 = n1 + 1;
        long n4 = (long) Math.pow(10, n.length() - 1);
        long n5 = n4 * 10 - n1;
        long n6 = n4 + n4 / 10;
        long n7 = n4 - n4 / 10;
        long n8 = n4 * 10 + n4 / 10;
        long n9 = n4 * 100 + n4 * 10 + n4 / 100;
        long n10 = n4 * 1000 + n4 * 100 + n4* 10 + n4 / 1000;
        return Math.min(Math.min(Math.min(Math.min(Math.min(Math.min(Math.min(Math.min(Math.min(n1, n2), n3), n4), n5), n6), n7), n8), n9), n10);  
    }
}