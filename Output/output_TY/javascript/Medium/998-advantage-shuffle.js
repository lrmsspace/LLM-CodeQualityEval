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
    let ans = new Array(n).fill(0);
    let sorted = nums1.slice().sort((a, b) => a - b);
    for (let i = 0; i < n; i++) {
        let target = nums2[i];
        let left = 0;
        let right = n - 1;
        let idx = -1;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (sorted[mid] > target) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
       if (idx == -1) {
        ans[i] = sorted.shift();
       }
    }
    return ans;
};