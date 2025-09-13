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
    const result = [];
    const n = num.length;

    const isValid = (a, b, c) => {
        return a + b === c && a <= 2 ** 31 - 1 && b <= 2 ** 31 - 1 && c <= 2 ** 31 - 1;
    };

    const backtrack = (start, a, b) => {
        if (start === n) {
            return result.length >= 3;
        }

        let c = '';
        for (let i = start; i < n; i++) {
            c += num[i];
            if (c.length > 1 && c[0] === '0') break; // Skip leading zeroes

            const numC = parseInt(c);
            if (isValid(a, b, numC)) {
                result.push(numC);
                if (backtrack(i + 1, b, numC)) {
                    return true;
                }
                result.pop();
            } else if (numC > a + b) {
                break; // No need to continue if numC is greater than a + b
            }
        }

        return false;
    };

    for (let i = 1; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const a = parseInt(num.slice(0, i));
            const b = parseInt(num.slice(i, j));
            if (a > 2 ** 31 - 1 || b > 2 ** 31 - 1) break; // Skip large numbers
            result.push(a);
            result.push(b);
            if (backtrack(j, a, b)) {
                return result;
            }
            result.pop();
            result.pop();
        }
    }

    return [];    
};