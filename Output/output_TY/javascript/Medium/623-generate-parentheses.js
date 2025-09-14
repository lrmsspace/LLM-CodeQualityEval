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
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let result = [];
    let stack = [];
    let left = n;
    let right = n;
    
    helper(left, right, stack, result);
    
    return result;
};

var helper = function(left, right, stack, result){
    if(left === 0 && right === 0){
        let str = '';
        for(let i = 0; i < stack.length; i++){
            str += stack[i];
        }
        result.push(str);
        return;
    }
    
    if(left > 0){
        stack.push('(');
        helper(left - 1, right, stack, result);
        )
    }
}
};