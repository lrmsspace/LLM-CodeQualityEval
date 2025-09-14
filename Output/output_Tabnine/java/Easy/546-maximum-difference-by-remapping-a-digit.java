/**https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/ */
//You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
//Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
//Notes:
//	When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
//	Bob can remap a digit to itself, in which case num does not change.
//	Bob can remap different digits for obtaining minimum and maximum values respectively.
//	The resulting number after remapping can contain leading zeroes.
// 
//Example 1:
//Input: num = 11891
//Output: 99009
//Explanation: 
//To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
//To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
//The difference between these two numbers is 99009.
//Example 2:
//Input: num = 90
//Output: 99
//Explanation:
//The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
//Thus, we return 99.
// 
//Constraints:
//	1 <= num <= 108
class Solution {
    public int minMaxDifference(int num) {
        String strNum = String.valueOf(num);
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (int i = 0; i < strNum.length(); i++) {
            for (char digit = '0'; digit <= '9'; digit++) {
                if (digit == strNum.charAt(i)) continue;
                String newStrNum = strNum.substring(0, i) + digit + strNum.substring(i + 1);
                int newNum = Integer.parseInt(newStrNum);
                max = Math.max(max, newNum);
                min = Math.min(min, newNum);
            }
        }
        return max - min;
        
    }
}