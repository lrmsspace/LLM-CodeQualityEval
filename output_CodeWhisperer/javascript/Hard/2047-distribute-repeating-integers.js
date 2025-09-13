/**https://leetcode.com/problems/distribute-repeating-integers/ */
//You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//	The ith customer gets exactly quantity[i] integers,
//	The integers the ith customer gets are all equal, and
//	Every customer is satisfied.
//Return true if it is possible to distribute nums according to the above conditions.
// 
//Example 1:
//Input: nums = [1,2,3,4], quantity = [2]
//Output: false
//Explanation: The 0th customer cannot be given two different integers.
//Example 2:
//Input: nums = [1,2,3,3], quantity = [2]
//Output: true
//Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
//Example 3:
//Input: nums = [1,1,2,2], quantity = [2,2]
//Output: true
//Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i] <= 1000
//	m == quantity.length
//	1 <= m <= 10
//	1 <= quantity[i] <= 105
//	There are at most 50 unique values in nums.
/**
 * @param {number[]} nums
 * @param {number[]} quantity
 * @return {boolean}
 */
var canDistribute = function(nums, quantity) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1);
        } else {
            map.set(nums[i], 1);
        }
    }
    let arr = [];
    for (let [key, value] of map) {
        arr.push(value);
    }
    quantity.sort((a, b) => b - a);
    let dp = new Array(1 << quantity.length).fill(-1);
    return dfs(arr, quantity, 0, 0, dp);
};