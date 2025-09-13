/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(auto c : s){
            if(c == '('){
                ++left;
            }
            else if(c == ')'){
                if(left){
                    --left;
                }
                else{
                    ++right;
                }
            }
        }

        unordered_set<string> result;
        dfs(s, 0, left, right, result);
        return vector<string>(result.begin(), result.end());
    }

private:
    void dfs(string& s, int start, int left, int right, unordered_set<string>&result){
        if(left == 0 && right == 0){
            if(isValid(s)){
                result.insert(s);
            }
        }
        else{
            for(int i = start; i < s.size(); ++i){
                if(i != start && s[i] == s[i - 1]){
                    continue;
                }
                if(left > 0 && s[i] == '('){
                    swap(s[i], s[start]);
                    dfs(s, start + 1, left - 1, right, result);
                    swap(s[i], s[start]);
                }
               if(right > 0 && s[i] == ')')
                {
                    swap(s[i], s[start]);
                    dfs(s, start + 1, left, right - 1, result);
                    swap(s[i], s[start]);
                    return;
                }
            }
        }
    }
};