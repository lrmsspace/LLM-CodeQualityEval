/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,3,4,4,5,6], k = 4
//Output: true
//Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
//Example 2:
//Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
//Output: true
//Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
//Example 3:
//Input: nums = [1,2,3,4], k = 3
//Output: false
//Explanation: Each array should be divided in subarrays of size 3.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 109
// 
//Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var isPossibleDivide = function(nums, k) {
    if (nums.length % k !== 0) {
        return false;
    }
    
    const freq = new Map();
    nums.sort((a, b) => a - b);
    
    for (const num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    
    for (const num of nums) {
        if (freq.get(num) === 0) {
            continue;
        }
        
        for (let i = 0; i < k; i++) {
            const curr = num + i;
            if (!freq.has(curr) || freq.get(curr) === 0) {
                return false;
            }
            
            freq.set(curr, freq.get(curr) - 1);
        }
    }
    
    return true;
    
};