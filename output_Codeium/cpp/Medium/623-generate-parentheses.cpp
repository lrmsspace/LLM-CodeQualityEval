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
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    
    void backtrack(vector<string>& res, string cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        
        if (open < n)
            backtrack(res, cur + "(", open + 1, close, n);
        if (close < open)
            backtrack(res, cur + ")", open, close + 1, n);
    }
};