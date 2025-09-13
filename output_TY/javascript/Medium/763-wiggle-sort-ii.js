/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
    let n = nums.length;
    let mid = Math.floor(n/2);
    let midNum = nums[mid];
    let left = 0;
    let right = n-1;
    let i = 0;
    while(i<=right){
        if(nums[i]>midNum){
            [nums[i],nums[right]] = [nums[right],nums[i]];
            right--;
        }else if(nums[i]<midNum){
            [nums[i],nums[left]] = [nums[left],nums[i]];
            left++;
            i++;
        }else{
            i++;
        }
    }
    let k = 1;
    let leftNum = nums[left-1];
    while(k<n){
        if(k%2===0){
            nums[k] = nums[--left];
        }else{
            nums[k] = nums[--right];
        }
        k++;
    }
    nums[0] = leftNum;
    return nums;
};