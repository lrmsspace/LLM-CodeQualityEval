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
        StringBuilder sb = new StringBuilder();
        boolean isNegative = num < 0;
        num = Math.abs(num);
        while(num > 0){
            sb.append(num % 7);
            num = num / 7;
        }
        return isNegative ? "-" + sb.reverse().toString() : sb.reverse().toString();

    }
}