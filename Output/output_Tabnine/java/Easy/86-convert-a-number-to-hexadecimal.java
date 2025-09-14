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
        StringBuilder sb = new StringBuilder();
        int mask = 0xf;
        
        if(num == 0) {
            return "0";
        }
        
        if(num < 0) {
            num = Math.abs(num) + (1 << 31);
        }
        
        while(num!= 0) {
            int digit = num & mask;
            if(digit < 10) {
                sb.append(digit);
            } else {
                sb.append((char) ('a' + (digit - 10)));
            }
            num = num >> 4;
        }
        
        return sb.reverse().toString();
        
    }
}