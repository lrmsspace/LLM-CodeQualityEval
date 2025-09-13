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
    const freqMap = new Map();
    const countMap = new Map();
    let maxCount = 0;
    let maxFreq = 0;
    
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        
        // Update frequency map
        const freq = freqMap.get(num) || 0;
        freqMap.set(num, freq + 1);
        
        // Update count map
        const count = countMap.get(freq) || 0;
        countMap.set(freq, count + 1);
        
        // Update maxCount and maxFreq
        maxCount = Math.max(maxCount, count);
        maxFreq = Math.max(maxFreq, freq);
        
        // Check if it's possible to remove one element
        if (freq === maxFreq && count === maxCount) {
            return i + 1;
        }
    }
    
    return -1;
    
};