/**https://leetcode.com/problems/smallest-good-base/ */
//Given an integer n represented as a string, return the smallest good base of n.
//We call k >= 2 a good base of n, if all digits of n base k are 1's.
// 
//Example 1:
//Input: n = "13"
//Output: "3"
//Explanation: 13 base 3 is 111.
//Example 2:
//Input: n = "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.
//Example 3:
//Input: n = "1000000000000000000"
//Output: "999999999999999999"
//Explanation: 1000000000000000000 base 999999999999999999 is 11.
// 
//Constraints:
//	n is an integer in the range [3, 1018].
//	n does not contain any leading zeros.
/**
 * @param {string} n
 * @return {string}
 */
var smallestGoodBase = function(n) {
    let num = BigInt(n);
    let maxM = BigInt(Math.floor(Math.log2(num)));
    for (let m = maxM; m > 1; m--) {
        let k = BigInt(Math.floor(Math.pow(num, 1 / m)));
        let mul = BigInt(1), sum = BigInt(1);
        for (let i = 1; i <= m; i++) {
            mul *= k;
            sum += mul;
        }
        if (sum === num) {
            return k.toString();
        }
    }
    return (num - 1n).toString();
};