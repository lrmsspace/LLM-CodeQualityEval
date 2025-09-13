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
    let fib = [];
    let i = 0;
    let j = 0;
    let k = 0;
    let n = num.length;
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let e = 0;
    let f = 0;
    let g = 0;
    let h = 0;
    let l = 0;
    let m = 0;
    let o = 0;
    let p = 0;
    let q = 0;
    let r = 0;
    let s = 0;
    let t = 0;
    while (i < n) {
        j = i + 1;
        while (j < n) {
            k = j + 1;
            while (k < n) {
                a = parseInt(num.slice(i, j));
                b = parseInt(num.slice(j, k));
                c = a + b;
                d = k;
                while (d < n) {
                    e = parseInt(num.slice(k, d));
                    f = e + c;
                    g = d;
                    while (g < n) {
                        h = g + 1;
                        while (h < n) {
                           l = parseInt(num.slice(d, g));
                        }
                    }
                }
            }
        }
    }
    return fib;

};