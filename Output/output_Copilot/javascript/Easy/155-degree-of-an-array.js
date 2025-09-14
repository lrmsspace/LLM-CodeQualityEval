/**https://leetcode.com/problems/degree-of-an-array/ */
//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
// 
//Example 1:
//Input: nums = [1,2,2,3,1]
//Output: 2
//Explanation: 
//The input array has a degree of 2 because both elements 1 and 2 appear twice.
//Of the subarrays that have the same degree:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//The shortest length is 2. So return 2.
//Example 2:
//Input: nums = [1,2,2,3,1,4,2]
//Output: 6
//Explanation: 
//The degree is 3 because the element 2 is repeated 3 times.
//So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
// 
//Constraints:
//	nums.length will be between 1 and 50,000.
//	nums[i] will be an integer between 0 and 49,999.
/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
    let map = new Map();
    let left = new Map();
    let right = new Map();
    let maxDegree = 0;
    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], 1);
            left.set(nums[i], i);
        } else {
            map.set(nums[i], map.get(nums[i]) + 1);
        }
        right.set(nums[i], i);
        maxDegree = Math.max(maxDegree, map.get(nums[i]));
    }
    let minLength = Infinity;
    for (let [key, value] of map) {
        if (value === maxDegree) {
            minLength = Math.min(minLength, right.get(key) - left.get(key) + 1);
        }
    }
    return minLength;    
};