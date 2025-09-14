/**https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/ */
//Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.
// 
//Example 1:
//Input: nums1 = [4,1,3], nums2 = [5,7]
//Output: 15
//Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
//Example 2:
//Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
//Output: 3
//Explanation: The number 3 contains the digit 3 which exists in both arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 9
//	1 <= nums1[i], nums2[i] <= 9
//	All digits in each array are unique.
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minNumber = function(nums1, nums2) {
    // Sort both arrays in descending order
    nums1.sort((a, b) => b - a);
    nums2.sort((a, b) => b - a);
    
    // Initialize the result as an empty string
    let result = '';
    
    // Iterate over the sorted arrays
    for (let i = 0, j = 0; i < nums1.length || j < nums2.length; ) {
        // Append the smaller digit to the result
        if (i < nums1.length && (j === nums2.length || nums1[i] <= nums2[j])) {
            result += nums1[i];
            i++;
        } else {
            result += nums2[j];
            j++;
        }
    }
    
    // Convert the result string to a number and return it
    return parseInt(result);
    
};