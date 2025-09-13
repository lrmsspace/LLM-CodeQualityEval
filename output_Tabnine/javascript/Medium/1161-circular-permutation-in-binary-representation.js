/**https://leetcode.com/problems/circular-permutation-in-binary-representation/ */
//Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
//	p[0] = start
//	p[i] and p[i+1] differ by only one bit in their binary representation.
//	p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
// 
//Example 1:
//Input: n = 2, start = 3
//Output: [3,2,0,1]
//Explanation: The binary representation of the permutation is (11,10,00,01). 
//All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]
//Example 2:
//Input: n = 3, start = 2
//Output: [2,6,7,5,4,0,1,3]
//Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).
// 
//Constraints:
//	1 <= n <= 16
//	0 <= start < 2 ^ n
/**

 * @param {number} n

 * @param {number} start

 * @return {number[]}

 */

var circularPermutation = function(n, start) {
    const size = 1 << n;
    const result = new Array(size).fill(0);
    let index = 0;
    const swap = (i, j) => {
        const temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    };
    const dfs = (depth) => {
        if (depth === n) {
            if (result[0] ^ start) {
                swap(0, size - 1);
            }
            return;
        }
        for (let i = 0; i < size - depth; i++) {
            if (result[i] ^ result[i + 1]) {
                swap(i, i + 1);
                dfs(depth + 1);
                swap(i, i + 1);
            }
        }
    };
    dfs(0);
    return result;

    

};