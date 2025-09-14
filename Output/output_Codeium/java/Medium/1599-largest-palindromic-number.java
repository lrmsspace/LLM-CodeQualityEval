/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
class Solution {
    public String largestPalindromic(String num) {
        int[] count = new int[10];
        for (char c : num.toCharArray()) {
            count[c - '0']++;
        }
        StringBuilder sb = new StringBuilder();
        int middle = -1;
        for (int i = 9; i >= 0; i--) {
            if (count[i] >= 2) {
                int n = count[i] / 2;
                while (n-- > 0) {
                    sb.append(i);
                }
            } else if (middle == -1) {
                middle = i;
            }
        }
        if (middle != -1) {
            sb.append(middle);
        }
        StringBuilder sb2 = new StringBuilder();
        for (int i = 0; i < sb.length(); i++) {
            sb2.append(sb.charAt(sb.length() - 1 - i));
        }
        return sb.toString() + (middle == -1 ? "" : middle + "") + sb2.toString();
    }
}