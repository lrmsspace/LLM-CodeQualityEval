/**https://leetcode.com/problems/binary-trees-with-factors/ */
//Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
//We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
//Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [2,4]
//Output: 3
//Explanation: We can make these trees: [2], [4], [4, 2, 2]
//Example 2:
//Input: arr = [2,4,5,10]
//Output: 7
//Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
// 
//Constraints:
//	1 <= arr.length <= 1000
//	2 <= arr[i] <= 109
//	All the values of arr are unique.
/**
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
    const MOD = 10 ** 9 + 7;
    const freq = new Map();
    arr.sort((a, b) => b - a);
    
    for (let num of arr) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    
    const dp = new Map();
    
    function countTrees(n) {
        if (dp.has(n)) return dp.get(n);
        
        let res = 0;
        
        for (let i = 2; i * i <= n; i++) {
            if (n % i === 0) {
                if (freq.has(i) && freq.has(n / i)) {
                    res = (res + countTrees(i) * countTrees(n / i)) % MOD;
                }
                if (i * i!== n) {
                    if (freq.has(n / i) && freq.has(i)) {
                        res = (res + countTrees(n / i) * countTrees(i)) % MOD;
                    }
                }
            }
        }
        
        return dp.set(n, res), res;
    }
    
    return countTrees(arr[0]);
    
};