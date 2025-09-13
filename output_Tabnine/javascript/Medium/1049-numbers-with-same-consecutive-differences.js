/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
// 
//Example 1:
//Input: n = 3, k = 7
//Output: [181,292,707,818,929]
//Explanation: Note that 070 is not a valid number, because it has leading zeroes.
//Example 2:
//Input: n = 2, k = 1
//Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
// 
//Constraints:
//	2 <= n <= 9
//	0 <= k <= 9
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function(n, k) {
    let result = [];
    let dfs = (digits, n) => {
        if (n === 0) {
            result.push(parseInt(digits.join('')));
            return;
        }
        
        let start = 0;
        if (digits.length > 0) {
            start = Math.max(0, parseInt(digits[digits.length - 1]) - k);
            if (start === parseInt(digits[digits.length - 1]) + k) start++;
        }
        
        for (let i = start; i <= 9; i++) {
            dfs(digits.concat(i.toString()), n - 1);
        }
    };
    
    dfs([], n);
    return result;
    
};