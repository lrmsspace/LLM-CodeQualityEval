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
    let factorial = Array(n + 1).fill(1);
    let nums = Array(n).fill(0).map((_, i) => i + 1);
    let result = [];
    
    for (let i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    
    k--;
    
    for (let i = n; i >= 1; i--) {
        let index = Math.floor(k / factorial[i - 1]);
        result.push(nums[index]);
        nums.splice(index, 1);
        k = k % factorial[i - 1];
    }
    
    return result.join('');
    
};