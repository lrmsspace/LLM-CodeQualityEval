/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], k = 10
//Output: 1
//Explanation: The only good subarray is the array nums itself.
//Example 2:
//Input: nums = [3,1,4,3,2,2,4], k = 2
//Output: 4
//Explanation: There are 4 different good subarrays:
//- [3,1,4,3,2,2] that has 2 pairs.
//- [3,1,4,3,2,2,4] that has 3 pairs.
//- [1,4,3,2,2,4] that has 2 pairs.
//- [4,3,2,2,4] that has 2 pairs.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], k <= 109
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countGood = function(nums, k) {
    const n = nums.length;
    const count = new Array(n + 1).fill(0);
    let res = 0;
    let prefixSum = new Map();
    prefixSum.set(0, 1);
    
    for (let i = 1; i <= n; i++) {
        count[i] = count[i - 1] + nums[i - 1];
        if (prefixSum.has(count[i] - k)) {
            res += prefixSum.get(count[i] - k);
        }
        prefixSum.set(count[i], (prefixSum.get(count[i]) || 0) + 1);
    }
    
    return res;
    
};