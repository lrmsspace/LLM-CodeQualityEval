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
        int len = n.length();
        int mid = len / 2;
        int left = mid - 1, right = mid;
        StringBuilder sb = new StringBuilder(n);
        
        // Find the closest palindrome by adjusting the digits
        while (left >= 0 && right < len) {
            if (sb.charAt(left) == sb.charAt(right)) {
                left--;
                right++;
            } else if (sb.charAt(left) < sb.charAt(right)) {
                sb.setCharAt(right, sb.charAt(left));
                break;
            } else {
                sb.setCharAt(left, sb.charAt(right));
                break;
            }
        }
        
        // Adjust the left and right digits to make the palindrome closest
        if (left >= 0 && right < len) {
            char leftDigit = sb.charAt(left);
            char rightDigit = sb.charAt(right);
            
            if (leftDigit == '9') {
                sb.setCharAt(left, '0');
                sb.setCharAt(right, '0');
            } else if (rightDigit == '9') {
                sb.setCharAt(left, leftDigit);
                sb.setCharAt(right, leftDigit);
            } else {
                sb.setCharAt(left, (char) (leftDigit + 1));
                sb.setCharAt(right, (char) (rightDigit + 1));
            }
        }
        
        return sb.toString();
        
    }
}