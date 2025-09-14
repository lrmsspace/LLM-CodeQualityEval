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
    for (let i = 0; i < (1 << n); ++i) {
        let s = '';
        for (let j = 0; j < n; ++j) {
            s += (i & (1 << j)) ? '1' : '0';
        }
        let valid = true;
        for (let j = 0; j < n - 1; ++j) {
            if (s[j] === '0' && s[j + 1] === '0') {
                valid = false;
                break;
            }
        }
        if (valid) {
            result.push(s);
        }
    }
    return result;
};