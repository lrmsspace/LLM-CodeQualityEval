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
    if (nums.length < 2) return 0;
    let max = Math.max(...nums);
    let min = Math.min(...nums);
    let bucketSize = Math.max(1, Math.ceil((max - min) / (nums.length - 1)));
    let bucketCount = Math.floor((max - min) / bucketSize) + 1;
    let buckets = Array.from({ length: bucketCount }, () => [Infinity, -Infinity]);
    
    for (let num of nums) {
        let index = Math.floor((num - min) / bucketSize);
        buckets[index][0] = Math.min(buckets[index][0], num);
        buckets[index][1] = Math.max(buckets[index][1], num);
    }
    
    let maxGap = 0;
    let prevMax = min;
    
    for (let i = 0; i < bucketCount; i++) {
        if (buckets[i][0] === Infinity) continue; // empty bucket
        maxGap = Math.max(maxGap, buckets[i][0] - prevMax);
        prevMax = buckets[i][1];
    }
    
    return maxGap;    
};