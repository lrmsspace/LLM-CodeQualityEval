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
    let count = {}, freq = {}, maxFreq = 0, maxCount = 0, n = nums.length;
    for (let i = 0; i < n; i++) {
        let num = nums[i];
        if (count[num]) {
            count[num]++;
            freq[count[num]] = (freq[count[num]] || 0) + 1;
            freq[count[num] - 1]--;
            if (freq[count[num] - 1] === 0) delete freq[count[num] - 1];
        } else {
            count[num] = 1;
            freq[1] = (freq[1] || 0) + 1;
        }
        maxFreq = Math.max(maxFreq, count[num]);
        maxCount = Math.max(maxCount, freq[maxFreq] || 0);
        if (maxCount === 1 && (maxFreq === 1 || freq[maxFreq - 1])) return i + 1;
    }
    return n;    
};