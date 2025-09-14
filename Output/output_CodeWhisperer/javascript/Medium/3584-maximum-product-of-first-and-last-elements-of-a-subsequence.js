/*
 You are given an integer array nums and an integer m.
 Return the maximum product of the first and last elements of any subsequence of nums of size m.
 Example 1:
 Input: nums = [-1,-9,2,3,-2,-3,1], m = 1
 Output: 81
 Explanation:
 The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.
 Example 2:
 Input: nums = [1,3,-5,5,6,-4], m = 3
 Output: 20
 Explanation:
 The subsequence [-5, 6, -4] has the largest product of the first and last elements.
 Example 3:
 Input: nums = [2,-1,2,-6,5,2,-5,7], m = 2
 Output: 35
 Explanation:
 The subsequence [5, 7] has the largest product of the first and last elements.
 Constraints:
 1 <= nums.length <= 105
 -105 <= nums[i] <= 105
 1 <= m <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
var maximumProduct = function(nums, m) {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let maxProduct = nums[n - 1] * nums[n - 2];
    let minProduct = nums[0] * nums[1];
    
    if (m === 1) {
        return Math.max(maxProduct, minProduct);
    }
    
    let left = 0;
    let right = n - 1;
    
    while (m > 1) {
        let leftProduct = nums[left] * nums[left + 1];
        let rightProduct = nums[right] * nums[right - 1];
        
        if (leftProduct * (m - 1) > rightProduct * (m - 1)) {
            maxProduct = Math.max(maxProduct, leftProduct);
            left += 1;
        } else {
            maxProduct = Math.max(maxProduct, rightProduct);
            right -= 1;
        }
        
        m -= 1;
    }
    
    return maxProduct * nums[right] * nums[left];
            
};