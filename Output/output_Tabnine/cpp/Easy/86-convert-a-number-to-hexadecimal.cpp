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
public:
    string toHex(int num) {
        string result = "";
        if (num == 0) {
            return "0";
        }
        
        int mask = 0xF;
        bool negative = num < 0;
        
        num = negative? -num : num;
        
        while (num!= 0) {
            int digit = num & mask;
            if (digit < 10) {
                result = to_string(digit) + result;
            } else {
                result = string(1, 'a' + digit - 10) + result;
            }
            num >>= 4;
        }
        
        return negative? "-" + result : result;
        
    }
};