/**https://leetcode.com/problems/backspace-string-compare/ */
//Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
//Note that after backspacing an empty text, the text will continue empty.
// 
//Example 1:
//Input: s = "ab#c", t = "ad#c"
//Output: true
//Explanation: Both s and t become "ac".
//Example 2:
//Input: s = "ab##", t = "c#d#"
//Output: true
//Explanation: Both s and t become "".
//Example 3:
//Input: s = "a#c", t = "b"
//Output: false
//Explanation: s becomes "c" while t becomes "b".
// 
//Constraints:
//	1 <= s.length, t.length <= 200
//	s and t only contain lowercase letters and '#' characters.
// 
//Follow up: Can you solve it in O(n) time and O(1) space?
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let s1 = [];
    let s2 = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '#') {
            s1.pop();
        } else {
            s1.push(s[i]);
        }
    }
    for (let i = 0; i < t.length; i++) {
        if (t[i] === '#') {
            s2.pop();
        } else {
            s2.push(t[i]);
        }
    }
    return s1.join('') === s2.join('');
};