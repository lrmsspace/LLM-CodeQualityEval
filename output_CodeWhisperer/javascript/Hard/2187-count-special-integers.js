/**https://leetcode.com/problems/count-special-integers/ */
//We call a positive integer special if all of its digits are distinct.
//Given a positive integer n, return the number of special integers that belong to the interval [1, n].
// 
//Example 1:
//Input: n = 20
//Output: 19
//Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
//Example 2:
//Input: n = 5
//Output: 5
//Explanation: All the integers from 1 to 5 are special.
//Example 3:
//Input: n = 135
//Output: 110
//Explanation: There are 110 integers from 1 to 135 that are special.
//Some of the integers that are not special are: 22, 114, and 131.
// 
//Constraints:
//	1 <= n <= 2 * 109
/**
 * @param {number} n
 * @return {number}
 */
var countSpecialNumbers = function(n) {
    let s = n.toString();
    let len = s.length;
    let res = 0;
    for (let i = 1; i < len; i++) {
        res += 9 * A(9, i - 1);
    }
    let seen = new Set();
    for (let i = 0; i < len; i++) {
        let j = 0;
        for (let d = (i === 0 ? 1 : 0); d < parseInt(s[i]); d++) {
            if (i === 0 && d === 0) continue;
            if (seen.has(d)) continue;
            res += A(9 - i, len - i - 1);
        }
        if (seen.has(parseInt(s[i]))) break;
        seen.add(parseInt(s[i]));
        if (i === len - 1) res++;
    }
    return res;

};