/**https://leetcode.com/problems/maximum-length-of-repeated-subarray/ */
//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
// 
//Example 1:
//Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//Output: 3
//Explanation: The repeated subarray with maximum length is [3,2,1].
//Example 2:
//Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//Output: 5
//Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 100
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findLength = function(nums1, nums2) {
    let n = nums1.length;
    let m = nums2.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(m + 1).fill(0));
    let ans = 0;
    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            if (nums1[i] == nums2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                ans = Math.max(ans, dp[i][j]);
            }
        }
    }
    return ans;
};