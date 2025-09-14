/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function(nums) {
    const mod = 1e9 + 7;
    const n = nums.length;
    const prefixSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    let count = 0;
    for (let i = 1; i < n - 1; i++) {
        let leftSum = prefixSum[i];
        let rightSum = prefixSum[n] - prefixSum[i + 1];
        if (leftSum > rightSum) break;
        let left = i + 1, right = n - 1;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (prefixSum[mid] - prefixSum[i] <= rightSum) {
                count += right - mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count % mod;    
};