/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//	Every letter in a is strictly less than every letter in b in the alphabet.
//	Every letter in b is strictly less than every letter in a in the alphabet.
//	Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.
// 
//Example 1:
//Input: a = "aba", b = "caa"
//Output: 2
//Explanation: Consider the best way to make each condition true:
//1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
//2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
//3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
//The best way was done in 2 operations (either condition 1 or condition 3).
//Example 2:
//Input: a = "dabadd", b = "cda"
//Output: 3
//Explanation: The best way is to make condition 1 true by changing b to "eee".
// 
//Constraints:
//	1 <= a.length, b.length <= 105
//	a and b consist only of lowercase letters.
/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var minCharacters = function(a, b) {
    let [minA, maxA] = [a.charCodeAt(0), a.charCodeAt(0)], [minB, maxB] = [b.charCodeAt(0), b.charCodeAt(0)];
    for (let i = 1; i < a.length; i++) {
        minA = Math.min(minA, a.charCodeAt(i));
        maxA = Math.max(maxA, a.charCodeAt(i));
    }
    for (let i = 1; i < b.length; i++) {
        minB = Math.min(minB, b.charCodeAt(i));
        maxB = Math.max(maxB, b.charCodeAt(i));
    }

    let diff = Math.max(0, maxA - minB + 1), same = 0;
    for (let i = 0; i < a.length; i++) if (a.charCodeAt(i) === b.charCodeAt(i)) same++;
    return Math.min(diff, a.length + b.length - 2 * same);
};