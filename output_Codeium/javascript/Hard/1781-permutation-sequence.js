/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//Given n and k, return the kth permutation sequence.
// 
//Example 1:
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//Input: n = 4, k = 9
//Output: "2314"
//Example 3:
//Input: n = 3, k = 1
//Output: "123"
// 
//Constraints:
//	1 <= n <= 9
//	1 <= k <= n!
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    // get the factorial of n
    function factorial(n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
    // calculate the kth permutation
    let res = '';
    let nums = Array.from({length: n}, (v, k) => k + 1);
    k--;
    while (n > 0) {
        n--;
        let idx = Math.floor(k / factorial(n));
        k %= factorial(n);
        res += nums[idx];
        nums.splice(idx, 1);
    }
    return res;
};