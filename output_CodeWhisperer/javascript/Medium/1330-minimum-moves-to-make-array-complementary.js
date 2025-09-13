/**https://leetcode.com/problems/minimum-moves-to-make-array-complementary/ */
//You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
//The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
//Return the minimum number of moves required to make nums complementary.
// 
//Example 1:
//Input: nums = [1,2,4,3], limit = 4
//Output: 1
//Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
//nums[0] + nums[3] = 1 + 3 = 4.
//nums[1] + nums[2] = 2 + 2 = 4.
//nums[2] + nums[1] = 2 + 2 = 4.
//nums[3] + nums[0] = 3 + 1 = 4.
//Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
//Example 2:
//Input: nums = [1,2,2,1], limit = 2
//Output: 2
//Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
//Example 3:
//Input: nums = [1,2,1,2], limit = 2
//Output: 0
//Explanation: nums is already complementary.
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 105
//	1 <= nums[i] <= limit <= 105
//	n is even.
/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number} 
 */
var minMoves = function(nums, limit) {
    // Create difference array with size 2*limit + 2
    const diff = new Array(2 * limit + 2).fill(0);
    const n = nums.length;
    
    // Process each pair
    for (let i = 0; i < n/2; i++) {
        const a = nums[i];
        const b = nums[n-1-i];
        const min = Math.min(a, b);
        const max = Math.max(a, b);
        
        // Mark ranges in difference array
        // For sum in [2, min+1): 2 moves needed
        diff[2] += 2;
        diff[min + 1] -= 2;
        
        // For sum in [min+1, max+1): 1 move needed
        diff[min + 1] += 1;
        diff[max + 1] -= 1;
        
        // For sum = max+min: 0 moves needed (already handled by previous ranges)
        
        // For sum in (max+min, max+limit+1]: 1 move needed
        diff[max + min + 1] += 1;
        diff[max + limit + 1] -= 1;
    }
    
    // Calculate minimum moves by scanning difference array
    let curr = 0;
    let minMoves = n; // Initialize with worst case
    
    // Only need to check possible sums from 2 to 2*limit
    for (let sum = 2; sum <= 2*limit; sum++) {
        curr += diff[sum];
        minMoves = Math.min(minMoves, curr);
    }
    
    return minMoves;
};
