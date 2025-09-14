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
        boolean isEven = len % 2 == 0;
        long num = Long.parseLong(n);
        long minDiff = Long.MAX_VALUE;
        long result = 0;
        long num1 = Long.parseLong(n.substring(0, (len + 1) / 2));
        for (long i = num1 - 1; i <= num1 + 1; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append(i);
            long j = isEven ? i : i / 10;
            while (j > 0) {
                sb.append(j % 10);
                j /= 10;
            }
            long num2 = Long.parseLong(sb.toString());
            if (num2 == num) {
                continue;
            }
            long diff = Math.abs(num2 - num);
            if (diff < minDiff) {
                minDiff = diff;
                result = num2;
            } else if (diff == minDiff) {
                result = Math.min(result, num2);
            }
        }
        return String.valueOf(result);      
    }
}