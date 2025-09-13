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
        vector<string> result;
        int left = 0, right = 0;
        for (auto c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left == 0) right++;
                else left--;
            }
        }
        string path;
        dfs(s, 0, left, right, path, result);
        return result;
        
    }
    void dfs(string s, int start, int left, int right, string path, vector<string>& result) {
        if (left == 0 && right == 0) {
            if (isValid(path + s.substr(start))) result.push_back(path + s.substr(start));
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (s[i] == '(' && left > 0) {
                dfs(s, i + 1, left - 1, right, path + s.substr(start, i - start) + "(", result);
            }
            else if (s[i] == ')' && right > 0) {
                dfs(s, i + 1, left, right - 1, path + s.substr(start, i - start) + ")", result);
            }
        }
    }
    bool isValid(string s) {
        int count = 0;
        for (auto c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                else count--;
            }
        }
        return count == 0;
    }
        
};