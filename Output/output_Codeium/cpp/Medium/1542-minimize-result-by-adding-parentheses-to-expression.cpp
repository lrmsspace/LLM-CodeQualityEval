/**https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/ */
//You are given a 0-indexed string expression of the form "<num1>+<num2>" where <num1> and <num2> represent positive integers.
//Add a pair of parentheses to expression such that after the addition of parentheses, expression is a valid mathematical expression and evaluates to the smallest possible value. The left parenthesis must be added to the left of '+' and the right parenthesis must be added to the right of '+'.
//Return expression after adding a pair of parentheses such that expression evaluates to the smallest possible value. If there are multiple answers that yield the same result, return any of them.
//The input has been generated such that the original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.
// 
//Example 1:
//Input: expression = "247+38"
//Output: "2(47+38)"
//Explanation: The expression evaluates to 2 * (47 + 38) = 2 * 85 = 170.
//Note that "2(4)7+38" is invalid because the right parenthesis must be to the right of the '+'.
//It can be shown that 170 is the smallest possible value.
//Example 2:
//Input: expression = "12+34"
//Output: "1(2+3)4"
//Explanation: The expression evaluates to 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20.
//Example 3:
//Input: expression = "999+999"
//Output: "(999+999)"
//Explanation: The expression evaluates to 999 + 999 = 1998.
// 
//Constraints:
//	3 <= expression.length <= 10
//	expression consists of digits from '1' to '9' and '+'.
//	expression starts and ends with digits.
//	expression contains exactly one '+'.
//	The original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.
class Solution {
public:
    string minimizeResult(string expression) {
        int pos = expression.find('+');
        int left = atoi(expression.substr(0, pos).c_str());
        int right = atoi(expression.substr(pos + 1).c_str());
        int min = INT_MAX;
        string result;
        for (int i = 0; i < pos; i++) {
            for (int j = pos + 1; j < expression.size(); j++) {
                int mul = atoi(expression.substr(0, i).c_str()) * (left + right) * atoi(expression.substr(j).c_str());
                if (mul < min) {
                    min = mul;
                    result = expression.substr(0, i) + "(" + expression.substr(i, pos - i) + "+" + expression.substr(pos + 1, j - pos - 1) + ")" + expression.substr(j);
                }
            }
        }
        return result;
    }
};