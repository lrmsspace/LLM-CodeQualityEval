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
        if(numerator == 0) return "0";
        string ans = "";
        if(numerator < 0 ^ denominator < 0) ans += '-';
        long n = labs(numerator), d = labs(denominator);
        ans += to_string(n / d);
        long remainder = n % d;
        if(remainder == 0) return ans;
        ans += '.';
        unordered_map<long, int> m;
        while(remainder != 0){
            if(m.find(remainder) != m.end()){
                ans.insert(m[remainder], "(");
                ans += ')';
                break;
            }
        }
        m[remainder] = ans.size();
        remainder *= 10;
        while(remainder != 0){
            ans += to_string(remainder / d);
            remainder %= d;
            if(remainder == 0) break;
            if(m.find(remainder) != m.end()){
                ans.insert(m[remainder], "(");
                ans += ')';
                break;
            }
            m[remainder] =ans.size();
        }
        return ans;
    }
};