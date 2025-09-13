/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.
// 
//Example 1:
//Input: num = 100
//Output: "202"
//Example 2:
//Input: num = -7
//Output: "-10"
// 
//Constraints:
//	-107 <= num <= 107
class Solution {
    public String convertToBase7(int num) {
        if(num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        boolean isNegative = num < 0;
        if(isNegative) num = -num;
        while(num > 0) {
            sb.insert(0, num % 7);
            num /= 7;
        }
        return isNegative ? "-" + sb.toString() : sb.toString();        
    }
}