/**https://leetcode.com/problems/rotated-digits/ */
//An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
//A number is valid if each digit remains a digit after rotation. For example:
//	0, 1, and 8 rotate to themselves,
//	2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
//	6 and 9 rotate to each other, and
//	the rest of the numbers do not rotate to any other number and become invalid.
//Given an integer n, return the number of good integers in the range [1, n].
// 
//Example 1:
//Input: n = 10
//Output: 4
//Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
//Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
//Example 2:
//Input: n = 1
//Output: 0
//Example 3:
//Input: n = 2
//Output: 1
// 
//Constraints:
//	1 <= n <= 104
/**
 * @param {number} n
 * @return {number}
 */
var rotatedDigits = function(n) {
    let count = 0;
    for (let i = 1; i <= n; i++) {
        let s = i.toString();
        let valid = true;
        let different = false;
        let seen = new Set();
        for (let c of s) {
            if (c === '3' || c === '4' || c === '7') {
                valid = false;
                break;
            }
            if (c === '0' || c === '1' || c === '8') {
                seen.add(c);
            } else if (c === '2') {
                seen.add('5');
            } else if (c === '5') {
                seen.add('2');
            } else if (c === '6') {
                seen.add('9');
            } else if (c === '9') {
                seen.add('6');
            }
            if (!seen.has(c)) {
                different = true;
            }
        }
        if (valid && different) {
            count++;
        }
    }
    return count;
    
};