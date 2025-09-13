/**https://leetcode.com/problems/maximal-score-after-applying-k-operations/ */
//You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
//In one operation:
//	choose an index i such that 0 <= i < nums.length,
//	increase your score by nums[i], and
//	replace nums[i] with ceil(nums[i] / 3).
//Return the maximum possible score you can attain after applying exactly k operations.
//The ceiling function ceil(val) is the least integer greater than or equal to val.
// 
//Example 1:
//Input: nums = [10,10,10,10,10], k = 5
//Output: 50
//Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
//Example 2:
//Input: nums = [1,10,3,3,3], k = 3
//Output: 17
//Explanation: You can do the following operations:
//Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
//Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
//Operation 3: Select i = 2, so nums becomes [1,2,1,3,3]. Your score increases by 3.
//The final score is 10 + 4 + 3 = 17.
// 
//Constraints:
//	1 <= nums.length, k <= 105
//	1 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxKelements = function(nums, k) {
    // Sort the array in descending order
    nums.sort((a, b) => b - a);
    
    let score = 0;
    let i = 0;
    
    // Perform k operations
    while (k > 0) {
        // Increase score by the current element
        score += nums[i];
        
        // Replace the current element with the ceiling of its division by 3
        nums[i] = Math.ceil(nums[i] / 3);
        
        // Increment the index
        i++;
        
        // Decrement the number of operations left
        k--;
    }
    
    return score;
    
};