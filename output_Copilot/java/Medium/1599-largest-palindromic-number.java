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
        char[] numChar = num.toCharArray();
        int[] count = new int[10];
        for (char c : numChar) {
            count[c - '0']++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < count[i]; j++) {
                sb.append(i);
            }
        }
        String s = sb.toString();
        int n = s.length();
        char[] res = new char[n];
        for (int i = 0; i < n; i++) {
            res[i] = s.charAt(i);
        }
        int[] index = new int[1];
        int[] max = new int[1];
        for (int i = 0; i < n; i++) {
            char[] temp = new char[n];
            for (int j = 0; j < n; j++) {
                temp[j] = res[j];
            }
            int l = i;
            int r = n - 1 - i;
            while (l < r) {
                temp[r] = temp[l];
                l++;
                r--;
            }
            int numInt = Integer.parseInt(new String(temp));
            if (numInt > max[0]) {
                max[0] = numInt;
                index[0] = i;
            }
        }
        char[] result = new char[n];
        for (int i = 0; i < n; i++) {
            result[i] = res[i];
        }
        int l = index[0];
        int r = n - 1 - index[0];
        while (l < r) {
            result[r] = result[l];
            l++;
            r--;
        }
        return new String(result);        
    }
}