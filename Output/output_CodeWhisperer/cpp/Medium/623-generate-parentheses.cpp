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
        if(n == 0){
            res.push_back("");
            return res;
        }
        for(int i = 0; i < n; i++){
            for(string left : generateParenthesis(i)){
                for(string right : generateParenthesis(n - i - 1)){
                    res.push_back("(" + left + ")" + right);
                }
            }
        }
        return res;      
    }
};