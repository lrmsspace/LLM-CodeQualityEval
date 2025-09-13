/**https://leetcode.com/problems/expression-add-operators/ */
//Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
//Note that operands in the returned expressions should not contain leading zeros.
// 
//Example 1:
//Input: num = "123", target = 6
//Output: ["1*2*3","1+2+3"]
//Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//Example 2:
//Input: num = "232", target = 8
//Output: ["2*3+2","2+3*2"]
//Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//Example 3:
//Input: num = "3456237490", target = 9191
//Output: []
//Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
// 
//Constraints:
//	1 <= num.length <= 10
//	num consists of only digits.    
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        backtrack(result, num, target, "", 0, 0, 0);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, const string& num, int target, 
                  string expr, int index, long currentVal, long lastOperand) {
        // Base case: reached the end of the number string
        if (index == num.size()) {
            // If the current value equals the target, add the expression to the result
            if (currentVal == target) {
                result.push_back(expr);
            }
            return;
        }
        
        // Try different lengths of operands starting from the current index
        for (int i = index; i < num.size(); i++) {
            // Skip leading zeros
            if (i > index && num[index] == '0') break;
            
            // Extract the current operand as a string and convert to long
            string operandStr = num.substr(index, i - index + 1);
            long operand = stol(operandStr);
            
            // If this is the first operand, there's no operator to add
            if (index == 0) {
                backtrack(result, num, target, operandStr, i + 1, operand, operand);
            } else {
                // Try adding '+'
                backtrack(result, num, target, expr + "+" + operandStr, i + 1, 
                         currentVal + operand, operand);
                
                // Try adding '-'
                backtrack(result, num, target, expr + "-" + operandStr, i + 1, 
                         currentVal - operand, -operand);
                
                // Try adding '*'
                // For multiplication, we need to handle operator precedence
                // We subtract the last operand, then add (last operand * current operand)
                backtrack(result, num, target, expr + "*" + operandStr, i + 1, 
                         currentVal - lastOperand + lastOperand * operand, lastOperand * operand);
            }
        }
    }
};
