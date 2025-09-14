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
    let countA = Array(26).fill(0);
    let countB = Array(26).fill(0);
    for (let char of a) {
        countA[char.charCodeAt() - 97]++;
    }
    for (let char of b) {
        countB[char.charCodeAt() - 97]++;
    }
    
    let minOperations = Infinity;
    
    // Case 1: All characters in a are less than all characters in b
    for (let i = 0; i < 25; i++) {
        let operations = a.length + b.length - (countA[i] + countB[i]);
        minOperations = Math.min(minOperations, operations);
    }
    
    // Case 2: All characters in b are less than all characters in a
    for (let i = 1; i < 26; i++) {
        let operations = a.length + b.length - (countA[i] + countB[i]);
        minOperations = Math.min(minOperations, operations);
    }
    
    // Case 3: Both strings consist of one distinct letter
    let maxCountA = Math.max(...countA);
    let maxCountB = Math.max(...countB);
    minOperations = Math.min(minOperations, a.length + b.length - Math.max(maxCountA, maxCountB));
    
    return minOperations;    
};