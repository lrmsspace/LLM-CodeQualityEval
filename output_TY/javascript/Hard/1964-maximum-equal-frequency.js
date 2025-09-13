/**https://leetcode.com/problems/maximum-equal-frequency/ */
//Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
//If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).
// 
//Example 1:
//Input: nums = [2,2,1,1,5,3,3,5]
//Output: 7
//Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4] = 5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
//Example 2:
//Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
//Output: 13
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxEqualFreq = function(nums) {
    let map = new Map();
    let count = new Map();
    let ans = 0;
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        let cnt = count.get(num) || 0;
        let cnt2 = cnt + 1;
        count.set(num, cnt2);
        let freq = map.get(cnt) || 0;
        map.set(cnt, freq - 1);
        freq = map.get(cnt2) || 0;
        map.set(cnt2, freq + 1);
        let max = Math.max(...map.keys());
    }
    return max <= 1 || max == Math.min(...map.keys());
};