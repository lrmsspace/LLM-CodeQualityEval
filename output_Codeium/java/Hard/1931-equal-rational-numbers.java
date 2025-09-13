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
        String[] sParts = s.contains("(") ? s.substring(0, s.indexOf('(')).split("\\.") : new String[] {s};
        String[] tParts = t.contains("(") ? t.substring(0, t.indexOf('(')).split("\\.") : new String[] {t};

        String sIntPart = sParts[0];
        String sFracPart = sParts.length > 1 ? sParts[1] : "";
        String sRepeatingPart = s.contains("(") ? s.substring(s.indexOf('(') + 1, s.indexOf(')')) : "";

        String tIntPart = tParts[0];
        String tFracPart = tParts.length > 1 ? tParts[1] : "";
        String tRepeatingPart = t.contains("(") ? t.substring(t.indexOf('(') + 1, t.indexOf(')')) : "";

        if (!sIntPart.equals(tIntPart)) {
            return false;
        }

        if (sFracPart.length > 0 && tFracPart.length > 0) {
            if (sRepeatingPart.length > 0 && tRepeatingPart.length > 0) {
                if (!sRepeatingPart.equals(tRepeatingPart)) {
                    return false;
                }
            } else if (sRepeatingPart.length > 0 || tRepeatingPart.length > 0) {
                return false;
            }
            int maxLength = Math.max(sFracPart.length(), tFracPart.length());
            for (int i = 0; i < maxLength; i++) {
                char sChar = i < sFracPart.length() ? sFracPart.charAt(i) : sRepeatingPart.charAt(i % sRepeatingPart.length());
                char tChar = i < tFracPart.length() ? tFracPart.charAt(i) : tRepeatingPart.charAt(i % tRepeatingPart.length());
                if (sChar != tChar) {
                    return false;
                }
            }
        } else if (sFracPart.length > 0 || tFracPart.length > 0) {
            return false;
        }
    }
}