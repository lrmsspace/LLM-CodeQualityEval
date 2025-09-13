/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === k) {
            let left = i - 1;
            let right = i + 1;
            let countLeft = 0;
            let countRight = 0;
            while (left >= 0 && nums[left] < k) {
                countLeft++;
                left--;
            }
            while (right < nums.length && nums[right] < k) {
                countRight++;
                right++;
            }
            count += (countLeft + 1) * (countRight + 1);
        }
    }
    return count;
    
};