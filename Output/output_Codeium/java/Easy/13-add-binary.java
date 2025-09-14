/**https://leetcode.com/problems/add-binary/ */
//Given two binary strings a and b, return their sum as a binary string.
// 
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist only of '0' or '1' characters.
//	Each string does not contain leading zeros except for the zero itself.
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int n1 = i >= 0 ? a.charAt(i--) - '0' : 0;
            int n2 = j >= 0 ? b.charAt(j--) - '0' : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 2;
            sb.append(tmp % 2);
        }
        return sb.reverse().toString();
    }
}