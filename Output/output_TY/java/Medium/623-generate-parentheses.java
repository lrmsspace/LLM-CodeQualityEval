/**https://leetcode.com/problems/generate-parentheses/ */
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 
//Example 1:
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//Example 2:
//Input: n = 1
//Output: ["()"]
// 
//Constraints:
//	1 <= n <= 8
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        generateParenthesis(result, "", n, n);
        return result;
    }

    private void generateParenthesis(List<String> result, String current, int left, int right) {
        if (left == 0 && right == 0) {
            result.add(current);
            return;
        }

        if (left > 0) {
            generateParenthesis(result, current + "(", left - 1, right);
        }

        if (right > left) {
            generateParenthesis(result, current + ")", left, right - 1);
        }
        return;
    }
}