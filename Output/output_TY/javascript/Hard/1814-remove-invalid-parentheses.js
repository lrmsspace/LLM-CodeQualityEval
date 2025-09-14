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
    let queue = [s];
    let visited = new Set();
    let found = false;
    while(queue.length){
        let current = queue.shift();
        if(isValid(current)){
            result.push(current);
            found = true;
        }
        if(found) continue;
        for(let i = 0; i < current.length; i++){
            if(current[i] !== '(' && current[i] !== ')') continue;
            let newString = current.slice(0,i) + current.slice(i+1);
            if(!visited.has(newString)){
                queue.push(newString);
            }
        }
    }
    return result;
};