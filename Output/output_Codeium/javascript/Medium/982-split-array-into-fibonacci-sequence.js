/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//	0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//	f.length >= 3, and
//	f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
// 
//Example 1:
//Input: num = "1101111"
//Output: [11,0,11,11]
//Explanation: The output [110, 1, 111] would also be accepted.
//Example 2:
//Input: num = "112358130"
//Output: []
//Explanation: The task is impossible.
//Example 3:
//Input: num = "0123"
//Output: []
//Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// 
//Constraints:
//	1 <= num.length <= 200
//	num contains only digits.
/**
 * @param {string} num
 * @return {number[]}
 */
var splitIntoFibonacci = function(num) {
    const res = [];
    backtrack(res, num, 0);
    return res.length >= 3 ? res : [];
}

function backtrack(res, num, start) {
    if (start === num.length) {
        return true;
    }
    for (let end = start + 1; end <= num.length; ++end) {
        const cur = Number(num.substring(start, end));
        if (res.length >= 2 && cur !== res[res.length - 1] + res[res.length - 2]) {
            return false;
        }
        if (cur >= 2**31 || (end > start + 1 && num[start] === '0')) {
            continue;
        }
        res.push(cur);
        if (backtrack(res, num, end)) {
            return true;
        }
        res.pop();
    }
    return false;
};