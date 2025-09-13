/**https://leetcode.com/problems/the-number-of-good-subsets/ */
//You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.
//	For example, if nums = [1, 2, 3, 4]:
//	
//		[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
//		[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
//	
//	
//Return the number of different good subsets in nums modulo 109 + 7.
//A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
// 
//Example 1:
//Input: nums = [1,2,3,4]
//Output: 6
//Explanation: The good subsets are:
//- [1,2]: product is 2, which is the product of distinct prime 2.
//- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
//- [1,3]: product is 3, which is the product of distinct prime 3.
//- [2]: product is 2, which is the product of distinct prime 2.
//- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
//- [3]: product is 3, which is the product of distinct prime 3.
//Example 2:
//Input: nums = [4,2,3,15]
//Output: 5
//Explanation: The good subsets are:
//- [2]: product is 2, which is the product of distinct prime 2.
//- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
//- [2,15]: product is 30, which is the product of distinct primes 2, 3, and 5.
//- [3]: product is 3, which is the product of distinct prime 3.
//- [15]: product is 15, which is the product of distinct primes 3 and 5.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 30
/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfGoodSubsets = function(nums) {
    const MOD = 1e9 + 7;
    const dp = Array(1 << 20).fill(0);
    dp[0] = 1;
    for (const num of nums) {
        const mask = 1 << (num - 1);
        for (let i = (1 << 20) - 1; i >= 0; i--) {
            if ((i & mask) === 0) {
                dp[i | mask] = (dp[i | mask] + dp[i]) % MOD;
            }
        }
    }
    let ans = dp.reduce((a, b) => a + b, 0);
    ans = (ans - 1 + MOD) % MOD;
    return ans;
};