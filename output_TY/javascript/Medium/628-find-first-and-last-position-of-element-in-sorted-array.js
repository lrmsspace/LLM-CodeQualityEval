/**https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.
// 
//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//Example 3:
//Input: nums = [], target = 0
//Output: [-1,-1]
// 
//Constraints:
//	0 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	nums is a non-decreasing array.
//	-109 <= target <= 109
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let start = 0, end = nums.length - 1, mid, ans = [];
    while(start <= end){
        mid = Math.floor((start + end) / 2);
        if(nums[mid] === target){
            ans.push(mid);
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    if(ans.length === 0){
        return [-1, -1];
    }
    start = ans[0];
    end = nums.length - 1;
    while(start <= end){
       mid = Math.floor((start + end) / 2);
    } 
    return [ans[0], mid];
};