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
            
            // Calculate the minimum number of parentheses to remove
            int leftToRemove = 0, rightToRemove = 0;
            
            for (char c : s) {
                if (c == '(') {
                    leftToRemove++;
                } else if (c == ')') {
                    if (leftToRemove > 0) {
                        leftToRemove--;
                    } else {
                        rightToRemove++;
                    }
                }
            }
            
            // Use backtracking to generate all valid strings
            unordered_set<string> uniqueResults;
            backtrack(s, 0, leftToRemove, rightToRemove, 0, "", uniqueResults);
            
            // Convert set to vector
            result.assign(uniqueResults.begin(), uniqueResults.end());
            return result;
        }
        
    private:
        void backtrack(const string& s, int index, int leftToRemove, int rightToRemove, 
                      int openCount, string current, unordered_set<string>& result) {
            // Base case: reached the end of the string
            if (index == s.size()) {
                // If we've removed all required parentheses and the string is valid
                if (leftToRemove == 0 && rightToRemove == 0 && openCount == 0) {
                    result.insert(current);
                }
                return;
            }
            
            char c = s[index];
            
            // Case 1: Remove the current character
            if (c == '(' && leftToRemove > 0) {
                backtrack(s, index + 1, leftToRemove - 1, rightToRemove, openCount, current, result);
            } else if (c == ')' && rightToRemove > 0) {
                backtrack(s, index + 1, leftToRemove, rightToRemove - 1, openCount, current, result);
            }
            
            // Case 2: Keep the current character
            current.push_back(c);
            
            if (c == '(') {
                backtrack(s, index + 1, leftToRemove, rightToRemove, openCount + 1, current, result);
            } else if (c == ')') {
                // We can only keep a closing parenthesis if there are matching opening ones
                if (openCount > 0) {
                    backtrack(s, index + 1, leftToRemove, rightToRemove, openCount - 1, current, result);
                }
            } else {
                // For non-parenthesis characters, just keep them
                backtrack(s, index + 1, leftToRemove, rightToRemove, openCount, current, result);
            }
            
            // Backtrack: remove the last character
            current.pop_back();
        }
    };
        