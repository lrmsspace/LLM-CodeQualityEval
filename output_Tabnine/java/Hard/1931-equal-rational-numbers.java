/**https://leetcode.com/problems/equal-rational-numbers/ */
//Given two strings s and t, each of which represents a non-negative rational number, return true if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.
//A rational number can be represented using up to three parts: <IntegerPart>, <NonRepeatingPart>, and a <RepeatingPart>. The number will be represented in one of the following three ways:
//	<IntegerPart>
//	
//		For example, 12, 0, and 123.
//	
//	
//	<IntegerPart><.><NonRepeatingPart>
//	
//		For example, 0.5, 1., 2.12, and 123.0001.
//	
//	
//	<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>
//	
//		For example, 0.1(6), 1.(9), 123.00(1212).
//	
//	
//The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:
//	1/6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66).
// 
//Example 1:
//Input: s = "0.(52)", t = "0.5(25)"
//Output: true
//Explanation: Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
//Example 2:
//Input: s = "0.1666(6)", t = "0.166(66)"
//Output: true
//Example 3:
//Input: s = "0.9(9)", t = "1."
//Output: true
//Explanation: "0.9(9)" represents 0.999999999... repeated forever, which equals 1.  [See this link for an explanation.]
//"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".
// 
//Constraints:
//	Each part consists only of digits.
//	The <IntegerPart> does not have leading zeros (except for the zero itself).
//	1 <= <IntegerPart>.length <= 4
//	0 <= <NonRepeatingPart>.length <= 4
//	1 <= <RepeatingPart>.length <= 4
class Solution {
    public boolean isRationalEqual(String s, String t) {
        // Remove the parentheses from the repeating part
        int start = s.indexOf('(');
        int end = s.lastIndexOf(')');
        if (start!= -1 && end!= -1) {
            s = s.substring(0, start) + s.substring(start + 1, end).replace('(', '0').replace(')', '1') + s.substring(end + 1);
            t = t.substring(0, start) + t.substring(start + 1, end).replace('(', '0').replace(')', '1') + t.substring(end + 1);
        }
        
        // Remove leading zeros from the integer and non-repeating parts
        s = s.replaceAll("^0+", "");
        t = t.replaceAll("^0+", "");
        
        // Compare the integer and non-repeating parts
        if (!s.substring(0, s.indexOf('.')).equals(t.substring(0, t.indexOf('.')))) {
            return false;
        }
        if (!s.substring(s.indexOf('.') + 1).equals(t.substring(t.indexOf('.') + 1))) {
            return false;
        }
        
        // Compare the repeating part
        int repeatingIndex = s.indexOf('(');
        if (repeatingIndex!= -1) {
            String repeatingPart = s.substring(repeatingIndex + 1, s.indexOf(')'));
            int repeatingLength = repeatingPart.length();
            for (int i = repeatingIndex + 1; i < s.length(); i++) {
                if (s.charAt(i) == repeatingPart.charAt(i % repeatingLength)) {
                    continue;
                }
                return false;
            }
        }
        
        return true;
        
    }
}