/**https://leetcode.com/problems/get-the-maximum-score/ */
//You are given two sorted arrays of distinct integers nums1 and nums2.
//A valid path is defined as follows:
//	Choose array nums1 or nums2 to traverse (from index-0).
//	Traverse the current array from left to right.
//	If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
//The score is defined as the sum of unique values in a valid path.
//Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
//Output: 30
//Explanation: Valid paths:
//[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
//[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
//The maximum is obtained with the path in green [2,4,6,8,10].
//Example 2:
//Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
//Output: 109
//Explanation: Maximum sum is obtained with the path [1,3,5,100].
//Example 3:
//Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
//Output: 40
//Explanation: There are no common elements between nums1 and nums2.
//Maximum sum is obtained with the path [6,7,8,9,10].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 105
//	1 <= nums1[i], nums2[i] <= 107
//	nums1 and nums2 are strictly increasing.
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxSum = function(nums1, nums2) {
    const MOD = 1e9 + 7;
    const m = nums1.length, n = nums2.length;
    const dp1 = new Array(m + 1).fill(0), dp2 = new Array(n + 1).fill(0);
    dp1[0] = dp2[0] = 0;
    let idx1 = 0, idx2 = 0;
    for (let i = 1; i <= m + n; i++) {
        if (idx1 < m && (idx2 === n || nums1[idx1] < nums2[idx2])) {
            dp1[i] = Math.max(dp1[i - 1], dp2[i - 1] + nums1[idx1++]);
        }
        if (idx2 < n && (idx1 === m || nums2[idx2] < nums1[idx1])) {
            dp2[i] = Math.max(dp2[i - 1], dp1[i - 1] + nums2[idx2++]);
        }
    }
    return Math.max(dp1[m + n], dp2[m + n]) % MOD;
};