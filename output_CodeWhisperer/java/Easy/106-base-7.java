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
        if (num < 0) return "-" + convertToBase7(-num);
        if (num < 7) return Integer.toString(num);
        return convertToBase7(num / 7) + Integer.toString(num % 7);      
    }
}