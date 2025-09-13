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
    const MAX = 30;
    const primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    const primeMask = new Array(MAX + 1).fill(0);
    const count = new Array(MAX + 1).fill(0);
    
    for (let i = 1; i <= MAX; i++) {
        let mask = 0;
        for (let j = 0; j < primes.length; j++) {
            if (i % primes[j] === 0) {
                mask |= (1 << j);
            }
        }
        primeMask[i] = mask;
    }
    
    for (const num of nums) {
        count[num]++;
    }
    
    let dp = new Array(1 << primes.length).fill(0);
    dp[0] = 1;
    
    for (let i = 1; i <= MAX; i++) {
        if (count[i] === 0 || primeMask[i] === 0) continue;
        
        for (let mask = (1 << primes.length) - 1; mask >= 0; mask--) {
            if ((mask & primeMask[i]) === primeMask[i]) {
                dp[mask ^ primeMask[i]] += dp[mask] * count[i];
                dp[mask ^ primeMask[i]] %= MOD;
            }
        }
    }
    
    let result = dp.reduce((acc, val) => (acc + val) % MOD);
    
    return result - 1;    
};