/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        if ((numerator > 0) ^ (denominator > 0)) {
            sb.append("-");
        }
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        long integerPart = num / den;
        sb.append(integerPart);
        num %= den;
        if (num == 0) {
            return sb.toString();
        }
        sb.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (num != 0) {
            if (map.containsKey(num)) {
                int start = map.get(num);
                sb.insert(start, "(");
                sb.append(")");
                return sb.toString();
            }
            map.put(num, sb.length());
            num *= 10;
            sb.append(num / den);
            num %= den;
        }
        return sb.toString();
    }
}