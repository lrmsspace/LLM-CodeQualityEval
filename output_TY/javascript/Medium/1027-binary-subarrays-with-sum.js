/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [1,0,1,0,1], goal = 2
//Output: 4
//Explanation: The 4 subarrays are bolded and underlined below:
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//Example 2:
//Input: nums = [0,0,0,0,0], goal = 0
//Output: 15
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	nums[i] is either 0 or 1.
//	0 <= goal <= nums.length
/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function(nums, goal) {
    let count = 0;
    let left = 0;
    let right = 0;
    let sum = 0;
    while (right < nums.length) {
        sum += nums[right];
        while (sum > goal) {
            sum -= nums[left];
            left++;
        }
        if (sum === goal) {
            let leftCount = 0;
            let rightCount = 0;
            while (left < right && nums[left] === 0) {
                leftCount++;
                left++;
            }
            while (right > left && nums[right] === 0) {
                rightCount++;
                right--;
            }
        }
    }
    return count;
};