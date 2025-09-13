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
    // Count the frequency of each number
    const count = nums.reduce((acc, num) => {
        acc[num] = (acc[num] || 0) + 1;
        return acc;
    }, {});
    
    // Sort the numbers in ascending order
    const sortedNums = nums.slice().sort((a, b) => a - b);
    
    // Iterate over the sorted numbers
    for (let i = 0; i < sortedNums.length; i++) {
        const num = sortedNums[i];
        
        // Check if there are enough occurrences of the current number to form a set of k consecutive numbers
        if (count[num] < k) return false;
        
        // Reduce the count of the current number and update the count of the next k numbers
        for (let j = 0; j < k; j++) {
            count[num + j]--;
        }
    }
    
    // All numbers have been used to form sets of k consecutive numbers
    return true;
    
};