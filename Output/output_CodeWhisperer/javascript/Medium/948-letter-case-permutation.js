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
    let queue = [s];
    while (queue.length > 0) {
        let current = queue.shift();
        if (current.length === 0) {
            result.push(current);
        } else {
            let char = current[0];
            if (char.match(/[a-zA-Z]/)) {
                queue.push(current.substring(1));
                queue.push(char.toLowerCase() + current.substring(1));
                queue.push(char.toUpperCase() + current.substring(1));
            } else {
                queue.push(current.substring(1));
                queue.push(char + current.substring(1));
            }
        }
    }
    return result;
};