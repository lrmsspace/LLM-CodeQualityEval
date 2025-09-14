/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    let max = Math.max(...nums);
    let min = Math.min(...nums);
    let gap = Math.floor((max-min)/(nums.length-1));
    let bucket = new Array(Math.floor((max-min)/gap)+1).fill(0).map(x=>[]);
    for(let i=0;i<nums.length;i++){
        let index = Math.floor((nums[i]-min)/gap);
        bucket[index].push(nums[i]);
    }
    let maxGap = 0;
    let prev = bucket[0][0];
    for(let i=0;i<bucket.length;i++){
        if(bucket[i].length>0){
            maxGap = Math.max(maxGap,bucket[i][0]-prev);
            prev = bucket[i][bucket[i].length-1];
        }
    }
    return maxGap;
};