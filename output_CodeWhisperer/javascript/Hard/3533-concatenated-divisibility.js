/*
 You are given an array of positive integers nums and a positive integer k.
 A permutation of nums is said to form a divisible concatenation if, when you concatenate the decimal representations of the numbers in the order specified by the permutation, the resulting number is divisible by k.
 Return the lexicographically smallest permutation (when considered as a list of integers) that forms a divisible concatenation. If no such permutation exists, return an empty list.
 Example 1:
 Input: nums = [3,12,45], k = 5
 Output: [3,12,45]
 Explanation:
 Permutation
 Concatenated Value
 Divisible by 5
 [3, 12, 45]
 31245
 Yes
 [3, 45, 12]
 34512
 No
 [12, 3, 45]
 12345
 Yes
 [12, 45, 3]
 12453
 No
 [45, 3, 12]
 45312
 No
 [45, 12, 3]
 45123
 No
 The lexicographically smallest permutation that forms a divisible concatenation is [3,12,45].
 Example 2:
 Input: nums = [10,5], k = 10
 Output: [5,10]
 Explanation:
 Permutation
 Concatenated Value
 Divisible by 10
 [5, 10]
 510
 Yes
 [10, 5]
 105
 No
 The lexicographically smallest permutation that forms a divisible concatenation is [5,10].
 Example 3:
 Input: nums = [1,2,3], k = 5
 Output: []
 Explanation:
 Since no permutation of nums forms a valid divisible concatenation, return an empty list.
 Constraints:
 1 <= nums.length <= 13
 1 <= nums[i] <= 105
 1 <= k <= 100
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var concatenatedDivisibility = function(nums, k) {
    let n = nums.length;
    let dp = new Array(1 << n).fill(-1);
    let ans = [];
    
    function dfs(mask, prev) {
        if (mask === (1 << n) - 1) {
            return true;
        }
        if (dp[mask] !== -1) {
            return dp[mask];
        }
        
        for (let i = 0; i < n; i++) {
            if (((mask >> i) & 1) === 0) {
                let newMask = mask | (1 << i);
                let num = prev * 10 ** (nums[i].toString().length) + nums[i];
                if (num % k === 0 && dfs(newMask, num % 1000000000)) {
                    dp[mask] = true;
                    return true;
                }
            }
        }
        
        dp[mask] = false;
        return false;
    }
    
    function backtrack(mask, prev, curr) {
        if (mask === (1 << n) - 1) {
            ans = curr.slice();
            return;
        }
        
        for (let i = 0; i < n; i++) {
            if (((mask >> i) & 1) === 0) {
                let newMask = mask | (1 << i);
                let num = prev * 10 ** (nums[i].toString().length) + nums[i];
                if (num % k === 0) {
                    curr.push(nums[i]);
                    backtrack(newMask, num % 1000000000, curr);
                    curr.pop();
                }
                if (ans.length > 0) {
                    break;
                }
            }
        }
    }
    
    dfs(0, 0);
    if (ans.length === 0) {
        return [];
    }
    
    backtrack(0, 0, []);
    return ans.sort((a, b) => a - b);
        
};