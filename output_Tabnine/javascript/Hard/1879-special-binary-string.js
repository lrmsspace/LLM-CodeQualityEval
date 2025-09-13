/**https://leetcode.com/problems/special-binary-string/ */
//Special binary strings are binary strings with the following two properties:
//	The number of 0's is equal to the number of 1's.
//	Every prefix of the binary string has at least as many 1's as 0's.
//You are given a special binary string s.
//A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
//Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.
// 
//Example 1:
//Input: s = "11011000"
//Output: "11100100"
//Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
//This is the lexicographically largest string possible after some number of swaps.
//Example 2:
//Input: s = "10"
//Output: "10"
// 
//Constraints:
//	1 <= s.length <= 50
//	s[i] is either '0' or '1'.
//	s is a special binary string.
/**
 * @param {string} s
 * @return {string}
 */
var makeLargestSpecial = function(s) {
    function helper(s, start, end) {
        let count = 0;
        for (let i = start; i <= end; i++) {
            if (s[i] === '1') count++;
        }
        return count;
    }
    
    function swap(s, i, j) {
        let temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    let n = s.length;
    let stack = [];
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') stack.push(i);
    }
    
    let result = '';
    while (stack.length > 1) {
        let i = stack.pop();
        let j = stack.pop();
        swap(s, i, j);
        result += '1' + s.slice(i + 1, j) + '0';
    }
    
    if (stack.length > 0) {
        let i = stack[0];
        result += '1' + s.slice(i + 1) + '0';
    }
    
    return result;
    
};