/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
//All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
//Note: You are not allowed to use any built-in library method to directly solve this problem.
// 
//Example 1:
//Input: num = 26
//Output: "1a"
//Example 2:
//Input: num = -1
//Output: "ffffffff"
// 
//Constraints:
//	-231 <= num <= 231 - 1
class Solution {
    public String toHex(int num) {
        if (num == 0) return "0";
        StringBuilder hex = new StringBuilder();
        char[] hexChars = "0123456789abcdef".toCharArray();
        for (int i = 0; i < 8 && num != 0; i++) {
            hex.insert(0, hexChars[num & 15]);
            num >>>= 4;
        }
        return hex.toString();        
    }
}