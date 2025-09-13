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
        StringBuilder sb=new StringBuilder();
        char[] hex={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num!=0){
            sb.append(hex[num&15]);
            num=num>>4;
        }
        return sb.reverse().toString();
    }
}