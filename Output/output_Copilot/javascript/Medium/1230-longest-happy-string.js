/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let result = '';
    while (a > 0 || b > 0 || c > 0) {
        if (result.endsWith('a') && result.endsWith('b')) {
            if (c > 0) {
                result += 'c';
                c--;
            } else if (a > 0) {
                result += 'a';
                a--;
            } else if (b > 0) {
                result += 'b';
                b--;
            }
        } else if (result.endsWith('b') && result.endsWith('c')) {
            if (a > 0) {
                result += 'a';
                a--;
            } else if (b > 0) {
                result += 'b';
                b--;
            } else if (c > 0) {
                result += 'c';
                c--;
            }
        } else if (result.endsWith('c') && result.endsWith('a')) {
            if (b > 0) {
                result += 'b';
                b--;
            } else if (c > 0) {
                result += 'c';
                c--;
            } else if (a > 0) {
                result += 'a';
                a--;
            }
        } else {
            if (a >= b && a >= c) {
                result += 'a';
                a--;
            } else if (b >= a && b >= c) {
                result += 'b';
                b--;
            } else {
                result += 'c';
                c--;
            }
        }
    }
    return result;    
};