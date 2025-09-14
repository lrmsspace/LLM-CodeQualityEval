/*
 You are given two integer arrays nums1 and nums2.
 From nums1 two elements have been removed, and all other elements have been increased (or decreased in the case of negative) by an integer, represented by the variable x.
 As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.
 Return the minimum possible integer x that achieves this equivalence.
 Example 1:
 Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]
 Output: -2
 Explanation:
 After removing elements at indices [0,4] and adding -2, nums1 becomes [18,14,10].
 Example 2:
 Input: nums1 = [3,5,5,3], nums2 = [7,7]
 Output: 2
 Explanation:
 After removing elements at indices [0,3] and adding 2, nums1 becomes [7,7].
 Constraints:
 3 <= nums1.length <= 200
 nums2.length == nums1.length - 2
 0 <= nums1[i], nums2[i] <= 1000
 The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by removing two elements and adding x to each element of nums1.
*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minimumAddedInteger = function(nums1, nums2) {
    let [min1, max1] = [Math.min(...nums1), Math.max(...nums1)];
    let [min2, max2] = [Math.min(...nums2), Math.max(...nums2)];
    let x = Math.max(min2-min1, max2-max1);
    return x;
};