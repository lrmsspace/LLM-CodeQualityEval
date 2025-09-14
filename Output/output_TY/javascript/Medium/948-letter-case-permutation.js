/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.
// 
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//	1 <= s.length <= 12
//	s consists of lowercase English letters, uppercase English letters, and digits.
/**
 * @param {string} s
 * @return {string[]}
 */
var letterCasePermutation = function(s) {
    let result = [];
    let current = [];
    let index = 0;
    
    function backtrack(s, current, index){
        if(index === s.length){
            result.push(current.join(''));
            return;
        }
        
        if(s[index] >= '0' && s[index] <= '9'){
            current.push(s[index]);
            backtrack(s, current, index+1);
            current.pop();
        }else{
            current.push(s[index].toLowerCase());
            backtrack(s, current, index+1);
            current.pop();
            current.push(s[index].toUpperCase());
        }
    }
    backtrack(s, current, index);
    return result;
};