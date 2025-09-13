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
    let max = 0;
    for(let i=0; i<nums1.length; i++){
        for(let j=0; j<nums2.length; j++){
            let count = 0;
            let k = i;
            let l = j;
            while(nums1[k] === nums2[l]){
                count++;
                k++;
                l++;
                if(k>=nums1.length || l>=nums2.length){
                    break;
                }
            }
            max = Math.max(max, count);
        }
    }
    return max;
};