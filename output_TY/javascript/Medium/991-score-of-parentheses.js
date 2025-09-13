/**https://leetcode.com/problems/score-of-parentheses/ */
//Given a balanced parentheses string s, return the score of the string.
//The score of a balanced parentheses string is based on the following rule:
//	"()" has score 1.
//	AB has score A + B, where A and B are balanced parentheses strings.
//	(A) has score 2 * A, where A is a balanced parentheses string.
// 
//Example 1:
//Input: s = "()"
//Output: 1
//Example 2:
//Input: s = "(())"
//Output: 2
//Example 3:
//Input: s = "()()"
//Output: 2
// 
//Constraints:
//	2 <= s.length <= 50
//	s consists of only '(' and ')'.
//	s is a balanced parentheses string.
/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
    let stack = [];
    for(let i=0;i<s.length;i++){
        if(s[i]==='('){
            stack.push(s[i]);
        }else{
            let temp = 0;
            while(stack[stack.length-1]!=='('){
                temp+=stack.pop()*2;
            }
            stack.pop();
            stack.push(temp);
        }
    }
    return stack.reduce((a,b)=>a+b);
};
