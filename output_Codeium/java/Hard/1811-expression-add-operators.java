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
//	-231 <= target <= 231 - 1
class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<>();
        backtrack(res, "", num, target, 0);
        return res;
    }
    
    private void backtrack(List<String> res, String path, String num, int target, int pos) {
        if (pos == num.length()) {
            if (target == 0) {
                res.add(path);
            }
            return;
        }
        for (int i = pos; i < num.length(); i++) {
            if (i != pos && num.charAt(pos) == '0') break;
            int cur = Integer.parseInt(num.substring(pos, i+1));
            if (pos == 0) {
                backtrack(res, path + cur, num, target - cur, i + 1);
            } else {
                backtrack(res, path + "+" + cur, num, target - cur, i + 1);
                backtrack(res, path + "-" + cur, num, target + cur, i + 1);
                backtrack(res, path + "*" + cur, num, target - cur + (cur * Integer.parseInt(path.substring(path.lastIndexOf('+') == -1 ? 0 : path.lastIndexOf('+') + 1))), i + 1);
            }
        }
            
    }
}