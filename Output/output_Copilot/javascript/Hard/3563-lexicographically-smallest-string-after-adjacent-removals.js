/*
 You are given a string s consisting of lowercase English letters.
 You can perform the following operation any number of times (including zero):
 Remove any pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
 Shift the remaining characters to the left to fill the gap.
 Return the lexicographically smallest string that can be obtained after performing the operations optimally.
 Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.
 Example 1:
 Input: s = "abc"
 Output: "a"
 Explanation:
 Remove "bc" from the string, leaving "a" as the remaining string.
 No further operations are possible. Thus, the lexicographically smallest string after all possible removals is "a".
 Example 2:
 Input: s = "bcda"
 Output: ""
 Explanation:
 ​​​​​​​Remove "cd" from the string, leaving "ba" as the remaining string.
 Remove "ba" from the string, leaving "" as the remaining string.
 No further operations are possible. Thus, the lexicographically smallest string after all possible removals is "".
 Example 3:
 Input: s = "zdce"
 Output: "zdce"
 Explanation:
 Remove "dc" from the string, leaving "ze" as the remaining string.
 No further operations are possible on "ze".
 However, since "zdce" is lexicographically smaller than "ze", the smallest string after all possible removals is "zdce".
 Constraints:
 1 <= s.length <= 250
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @return {string}
 */
var lexicographicallySmallestString = function(s) {
    const stack = [];
    for (let i = 0; i < s.length; i++) {
        const curr = s[i];
        while (stack.length && isAdjacent(stack[stack.length - 1], curr)) {
            stack.pop();
        }
        stack.push(curr);
    }
    return stack.join('');
};

const isAdjacent = (a, b) => {
    const diff = Math.abs(a.charCodeAt(0) - b.charCodeAt(0));
    return diff === 1 || diff === 25;
};