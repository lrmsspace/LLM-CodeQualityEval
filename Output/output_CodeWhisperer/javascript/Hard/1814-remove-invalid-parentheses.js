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
    let res = [];
    let visited = new Set();
    let queue = [s];
    let found = false;
    while (queue.length > 0) {
        let str = queue.shift();
        if (isValid(str)) {
            res.push(str);
            found = true;
        }
        if (found) continue;
        for (let i = 0; i < str.length; i++) {
            if (str[i] !== '(' && str[i] !== ')') continue;
            let newStr = str.substring(0, i) + str.substring(i + 1);
            if (!visited.has(newStr)) {
                queue.push(newStr);
                visited.add(newStr);
            }
        }
    }
    return res;
    
    function isValid(str) {
        let count = 0;
        for (let i = 0; i < str.length; i++) {
            if (str[i] === '(') count++;
            if (str[i] === ')') count--;
            if (count < 0) return false;
        }
        return count === 0;
    }
};