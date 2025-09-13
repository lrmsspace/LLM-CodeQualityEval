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
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        bool isNegative = (numerator < 0) ^ (denominator < 0);
        long long num = abs(static_cast<long long>(numerator)), den = abs(static_cast<long long>(denominator));
        
        string integerPart = to_string(num / den);
        string fractionPart = "";
        
        if (num % den == 0) {
            return (isNegative? "-" : "") + integerPart;
        }
        
        num %= den;
        unordered_map<int, int> remainderMap;
        
        while (num!= 0) {
            if (remainderMap.find(num)!= remainderMap.end()) {
                int repeatIndex = remainderMap[num];
                fractionPart = fractionPart.substr(0, repeatIndex) + "(" + fractionPart.substr(repeatIndex) + ")";
                break;
            }
            
            remainderMap[num] = fractionPart.size();
            num *= 10;
            fractionPart += to_string(num / den);
        }
        
        return (isNegative? "-" : "") + integerPart + (fractionPart.empty()? "" : "." + fractionPart);
        
    }
};