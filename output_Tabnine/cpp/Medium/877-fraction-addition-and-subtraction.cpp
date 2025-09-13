/**https://leetcode.com/problems/fraction-addition-and-subtraction/ */
//Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
//The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
// 
//Example 1:
//Input: expression = "-1/2+1/2"
//Output: "0/1"
//Example 2:
//Input: expression = "-1/2+1/2+1/3"
//Output: "1/3"
//Example 3:
//Input: expression = "1/3-1/2"
//Output: "-1/6"
// 
//Constraints:
//	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
//	Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
//	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
//	The number of given fractions will be in the range [1, 10].
//	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
class Solution {
public:
    string fractionAddition(string expression) {
        int sign = 1;
        int i = 0, n = expression.size();
        long long numerator = 0, denominator = 0, prevNumerator = 0, prevDenominator = 1;
        
        while (i < n) {
            if (expression[i] == '-') sign = -1;
            else if (expression[i] == '+') sign = 1;
            else if (expression[i] == '/') {
                numerator = prevNumerator * (sign * (expression[i + 1] - '0'));
                denominator = prevDenominator * (expression[i - 1] - '0');
                i += 2;
            } else {
                numerator = prevNumerator * 10 + (expression[i] - '0');
                i++;
            }
            
            prevNumerator = numerator;
            prevDenominator = denominator;
        }
        
        numerator = prevNumerator * sign;
        denominator = prevDenominator;
        
        if (denominator == 1) return to_string(numerator);
        
        int gcd = abs(__gcd(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
        
        return to_string(numerator) + "/" + to_string(denominator);
        
    }
};