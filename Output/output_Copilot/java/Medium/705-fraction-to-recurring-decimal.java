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
        if (numerator == 0) return "0";
        StringBuilder sb = new StringBuilder();
        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0)) sb.append('-');
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        sb.append(num / den); // Integer part
        num %= den; // Remainder

        if (num == 0) return sb.toString(); // No fractional part

        sb.append('.'); // Decimal point
        Map<Long, Integer> map = new HashMap<>(); // Map to store the position of the remainder
        map.put(num, sb.length()); // Store the position of the first occurrence of the remainder

        while (num != 0) {
            num *= 10;
            sb.append(num / den); // Append the next digit
            num %= den; // Update the remainder

            if (map.containsKey(num)) { // Check if the remainder has occurred before
                int pos = map.get(num); // Get the position of the first occurrence
                sb.insert(pos, '('); // Insert '(' at that position
                sb.append(')'); // Append ')' at the end
                break;
            } else {
                map.put(num, sb.length()); // Store the position of the current remainder
            }
        }

        return sb.toString();        
    }
}