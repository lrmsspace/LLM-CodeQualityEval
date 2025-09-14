/**https://leetcode.com/problems/contains-duplicate-iii/ */
//You are given an integer array nums and two integers indexDiff and valueDiff.
//Find a pair of indices (i, j) such that:
//	i != j,
//	abs(i - j) <= indexDiff.
//	abs(nums[i] - nums[j]) <= valueDiff, and
//Return true if such pair exists or false otherwise.
// 
//Example 1:
//Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
//Output: true
//Explanation: We can choose (i, j) = (0, 3).
//We satisfy the three conditions:
//i != j --> 0 != 3
//abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
//abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
//Example 2:
//Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
//Output: false
//Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
// 
//Constraints:
//	2 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	1 <= indexDiff <= nums.length
//	0 <= valueDiff <= 109
/**
 * @param {number[]} nums
 * @param {number} indexDiff
 * @param {number} valueDiff
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    // Initialize a min heap to store the absolute difference of indices and their corresponding values
    const minHeap = [];
    
    // Iterate through the given array
    for (let i = 0; i < nums.length; i++) {
        // If the min heap is not empty and the absolute difference of indices is greater than indexDiff, remove the pair with the smallest absolute difference
        if (minHeap.length > 0 && Math.abs(minHeap[0][0] - i) > indexDiff) {
            heapify(minHeap, 0, minHeap.length - 1);
            minHeap.pop();
        }
        
        // Iterate through the min heap to find pairs with values that are within valueDiff
        for (let j = 0; j < minHeap.length && Math.abs(nums[i] - minHeap[j][1]) <= valueDiff; j++) {
            if (Math.abs(minHeap[j][0] - i) <= indexDiff) {
                return true;
            }
        }
        
        // Add the current pair to the min heap
        minHeap.push([-Math.abs(i - minHeap[0][0]), nums[i]]);
    }
    
    // Heapify the min heap
    heapify(minHeap, 0, minHeap.length - 1);
    
    return false;
    
};