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
public:
    bool isRationalEqual(string s, string t) {
        int i = 0, j = 0;
        int s_int = 0, t_int = 0;
        int s_non = 0, t_non = 0;
        int s_rep = 0, t_rep = 0;
        bool s_rep_exist = false, t_rep_exist = false;
        while (i < s.size()) {
            if (s[i] == '.') {
                i++;
                break;
            }
            s_int = s_int * 10 + (s[i++] - '0');
        }
        while (j < t.size()) {
            if (t[j] == '.') {
                j++;
                break;
            }
            t_int = t_int * 10 + (t[j++] - '0');
        }
        while (i < s.size()) {
            if (s[i] == '(') {
                s_rep_exist = true;
                i++;
                break;
            }
            s_non = s_non * 10 + (s[i++] - '0');
        }
        while (j < t.size()) {
            if (t[j] == '(') {
                t_rep_exist = true;
                j++;
                break;
            }
            t_non = t_non * 10 + (t[j++] - '0');
        }
        if (s_rep_exist) {
            int k = i;
            while (i < s.size() && s[i] != ')') {
                s_rep = s_rep * 10 + (s[i++] - '0');
            }
            i = k;
        }
        if (t_rep_exist) {
            int k = j;
            while (j < t.size() && t[j] != ')') {
                t_rep = t_rep * 10 + (t[j++] - '0');
            }
            j = k;
        }
        if (s_int != t_int) return false;
        if (s_non != t_non) return false;
        if (s_rep != t_rep) return false;
        if (s_rep_exist && !t_rep_exist) return false;
        if (!s_rep_exist && t_rep_exist) return false;
    }
};