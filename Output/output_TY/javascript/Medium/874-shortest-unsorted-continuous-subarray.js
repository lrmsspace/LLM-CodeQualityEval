/**https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ */
//Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
//Return the shortest such subarray and output its length.
// 
//Example 1:
//Input: nums = [2,6,4,8,10,9,15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 0
//Example 3:
//Input: nums = [1]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 104
//	-105 <= nums[i] <= 105
// 
//Follow up: Can you solve it in O(n) time complexity?
/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    let start = 0, end = nums.length - 1;
    let min = Number.MAX_SAFE_INTEGER, max = Number.MIN_SAFE_INTEGER;
    while(start < end){
        if(nums[start] <= nums[end]){
            start++;
        }else{
            max = Math.max(max, nums[start]);
            min = Math.min(min, nums[end]);
            end--;
        }
    }
    while(start > 0 && nums[start - 1] > min){
        start--;
    }
    while(end < nums.length - 1 && nums[end + 1] < max){
        end++;
    }
    return end - start + 1;
};