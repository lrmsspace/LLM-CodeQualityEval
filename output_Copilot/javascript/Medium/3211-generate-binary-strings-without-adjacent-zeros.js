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

    function generate(current) {
        if (current.length === n) {
            result.push(current);
            return;
        }

        // Add '0' if the last character is not '0'
        if (current.length < 2 || current[current.length - 1] !== '0') {
            generate(current + '0');
        }

        // Always add '1'
        generate(current + '1');
    }

    // Start with an empty string
    generate('');

    return result;
        
};