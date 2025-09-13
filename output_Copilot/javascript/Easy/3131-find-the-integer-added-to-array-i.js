/*
 You are given two arrays of equal length, nums1 and nums2.
 Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.
 As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.
 Return the integer x.
 Example 1:
 Input: nums1 = [2,6,4], nums2 = [9,7,5]
 Output: 3
 Explanation:
 The integer added to each element of nums1 is 3.
 Example 2:
 Input: nums1 = [10], nums2 = [5]
 Output: -5
 Explanation:
 The integer added to each element of nums1 is -5.
 Example 3:
 Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]
 Output: 0
 Explanation:
 The integer added to each element of nums1 is 0.
 Constraints:
 1 <= nums1.length == nums2.length <= 100
 0 <= nums1[i], nums2[i] <= 1000
 The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by adding x to each element of nums1.
*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var addedInteger = function(nums1, nums2) {
    if (nums1.length !== nums2.length) {
        throw new Error("Input arrays must have the same length.");
    }

    // Calculate the difference between the first elements
    const difference = nums2[0] - nums1[0];

    // Check if adding the difference to all elements of nums1 makes it equal to nums2
    for (let i = 0; i < nums1.length; i++) {
        if (nums1[i] + difference !== nums2[i]) {
            return null; // If any element does not match, return null
        }
    }

    return difference; // Return the integer added to each element
    
};