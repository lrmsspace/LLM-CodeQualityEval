/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.
// 
//Example 1:
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
//Example 2:
//Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//Output: [24,32,8,12]
// 
//Constraints:
//	1 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 109
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var advantageCount = function(nums1, nums2) {
    let n = nums1.length;
    let idx1 = new Array(n).fill(0).map((_, i) => i);
    let idx2 = new Array(n).fill(0).map((_, i) => i);
    idx1.sort((a, b) => nums1[a] - nums1[b]);
    idx2.sort((a, b) => nums2[a] - nums2[b]);
    let ans = new Array(n).fill(0);
    let left = 0, right = n - 1;
    for (let i = 0; i < n; i++) {
        if (nums1[idx1[i]] > nums2[idx2[left]]) {
            ans[idx2[left]] = nums1[idx1[i]];
            left++;
        } else {
            ans[idx2[right]] = nums1[idx1[i]];
            right--;
        }
    }
    return ans; 
};