/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.
// 
//Example 1:
//Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
//Output: [9,8,6,5,3]
//Example 2:
//Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
//Output: [6,7,6,0,4]
//Example 3:
//Input: nums1 = [3,9], nums2 = [8,9], k = 3
//Output: [9,8,9]
// 
//Constraints:
//	m == nums1.length
//	n == nums2.length
//	1 <= m, n <= 500
//	0 <= nums1[i], nums2[i] <= 9
//	1 <= k <= m + n
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[]}
 */
var maxNumber = function(nums1, nums2, k) {
    let max = [];
    for(let i = 0; i <= k; i++){
        let num1 = nums1.slice(0,i);
        let num2 = nums2.slice(0,k-i);
        let num3 = nums1.slice(i,k);
        let num4 = nums2.slice(k-i,k);
        let num5 = num1.concat(num2);
        let num6 = num3.concat(num4);
        let num7 = [];
        let num8 = [];
        for(let j = 0; j < num5.length; j++){
            while(num7.length > 0 && num7[num7.length-1] < num5[j] && num6.length > 0){
                num7.pop();
            }
        }
    }
    return max;
};