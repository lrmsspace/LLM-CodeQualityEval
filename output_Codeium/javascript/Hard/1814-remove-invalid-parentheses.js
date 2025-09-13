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
/**
 * @param {string} s
 * @return {string[]}
 */
var removeInvalidParentheses = function(s) {
    let result = [];
    let minRemove = Infinity;
    const dfs = (path, idx, left, right, remove) => {
        if (idx === s.length) {
            if (left === 0 && right === 0 && remove < minRemove) {
                minRemove = remove;
                result = [path];
            }
            else if (left === 0 && right === 0 && remove === minRemove) {
                result.push(path);
            }
            return;
        }
        if (s[idx] === '(') {
            dfs(path + '(', idx + 1, left + 1, right, remove);
            dfs(path, idx + 1, left, right, remove + 1);
        }
        else if (s[idx] === ')') {
            if (left > right) {
                dfs(path + ')', idx + 1, left, right + 1, remove);
            }
            dfs(path, idx + 1, left, right, remove + 1);
        }
        else {
            dfs(path + s[idx], idx + 1, left, right, remove);
        }
    }
    dfs('', 0, 0, 0, 0);
    return result;
};