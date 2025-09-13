/*
 You are given a 0-indexed array nums of non-negative integers, and two integers l and r.
 Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].
 Since the answer may be large, return it modulo 109 + 7.
 A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.
 Note that:
 Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
 The sum of an empty multiset is 0.
 Example 1:
 Input: nums = [1,2,2,3], l = 6, r = 6
 Output: 1
 Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
 Example 2:
 Input: nums = [2,1,4,2,7], l = 1, r = 5
 Output: 7
 Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
 Example 3:
 Input: nums = [1,2,1,3,5,2], l = 3, r = 5
 Output: 9
 Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.
 Constraints:
 1 <= nums.length <= 2 * 104
 0 <= nums[i] <= 2 * 104
 Sum of nums does not exceed 2 * 104.
 0 <= l <= r <= 2 * 104
*/

/**
 * @param {number[]} nums
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var countSubMultisets = function(nums, l, r) {
    const mod = 10**9 + 7;
    const freq = new Map();
    for (const num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    
    const dp = new Array(r + 1).fill(0);
    dp[0] = 1;
    
    for (const [num, count] of freq) {
        const sum = num * count;
        if (sum < r + 1) {
            for (let i = r; i >= sum; i--) {
                dp[i] = (dp[i] + dp[i - sum]) % mod;
                if (i >= (num + 1) * count) {
                    dp[i] = (dp[i] - dp[i - (num + 1) * count] + mod) % mod;
                }
            }
        } else {
            const tmp = new Array(r + 1).fill(0);
            tmp[0] = 1;
            for (let i = 0; i < num; i++) {
                for (let j = 0; j <= r; j++) {
                    if (i == 0) {
                        tmp[j] = dp[j];
                    } else {
                        tmp[j] = (tmp[j] + tmp[j - num]) % mod;
                        if (j >= num + 1) {
                            tmp[j] = (tmp[j] - tmp[j - num - 1] + mod) % mod;
                        }
                    }
                }
            }
            dp[num] = (dp[num] + tmp[r] - tmp[num - 1] + mod) % mod;
        }
    }
    
    let res = 0;
    for (let i = l; i <= r; i++) {
        res = (res + dp[i]) % mod;
    }
    
    return res;        
};