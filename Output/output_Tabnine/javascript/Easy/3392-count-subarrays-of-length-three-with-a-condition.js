/*
 Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
 Example 1:
 Input: nums = [1,2,1,4,1]
 Output: 1
 Explanation:
 Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
 Example 2:
 Input: nums = [1,1,1]
 Output: 0
 Explanation:
 [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.
 Constraints:
 3 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var countSubarrays = function(nums) {
    const n = nums.length;
    const prefixSum = new Array(n + 1).fill(0);
    const target = nums[n - 1] / 2;
    
    for (let i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    
    let count = 0;
    for (let i = 2; i < n; i++) {
        const leftSum = prefixSum[i - 2];
        const rightSum = prefixSum[n] - prefixSum[i];
        
        if (leftSum + rightSum === target * 2) {
            count++;
        }
    }
    
    return count;
    
};