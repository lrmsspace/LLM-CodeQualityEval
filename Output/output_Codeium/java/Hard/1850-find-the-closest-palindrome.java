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
        long num = Long.parseLong(n);
        long lower = num - 1, upper = num + 1;
        while (true) {
            if (isPalindrome(lower)) return String.valueOf(lower);
            if (isPalindrome(upper)) return String.valueOf(upper);
            lower--;
            upper++;
        }

    private boolean isPalindrome(long num) {
        String str = String.valueOf(num);
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
        
    }
}