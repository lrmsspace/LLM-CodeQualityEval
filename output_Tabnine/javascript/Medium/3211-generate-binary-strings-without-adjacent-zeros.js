/*
 You are given a positive integer n.
 A binary string x is valid if all substrings of x of length 2 contain at least one "1".
 Return all valid strings with length n, in any order.
 Example 1:
 Input: n = 3
 Output: ["010","011","101","110","111"]
 Explanation:
 The valid strings of length 3 are: "010", "011", "101", "110", and "111".
 Example 2:
 Input: n = 1
 Output: ["0","1"]
 Explanation:
 The valid strings of length 1 are: "0" and "1".
 Constraints:
 1 <= n <= 18
*/

/**
 * @param {number} n
 * @return {string[]}
 */
var validStrings = function(n) {
    const result = [];
    
    const backtrack = (curr, left, right) => {
        if (curr.length === n) {
            result.push(curr);
            return;
        }
        
        if (left < n) {
            backtrack(curr + '0', left + 1, right);
        }
        
        if (right < left) {
            backtrack(curr + '1', left, right + 1);
        }
    };
    
    backtrack('', 0, 0);
    
    return result;
    
};