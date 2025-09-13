/**https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
// 
//Example 1:
//Input: nums = [3,6,2,7,1], k = 6
//Output: 4
//Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//Example 2:
//Input: nums = [3], k = 2
//Output: 0
//Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i], k <= 1000
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayLCM = function(nums, k) {
    // Initialize variables
    let count = 0;
    let prefixProduct = 1;
    
    // Create a map to store the count of each product
    const productCount = new Map();
    productCount.set(1, 1);
    
    // Iterate through the array
    for (let i = 0; i < nums.length; i++) {
        // Calculate the product of the current element and the prefix product
        prefixProduct = (prefixProduct * nums[i]) % k;
        
        // If the product is already in the map, increment its count
        if (productCount.has(prefixProduct)) {
            count += productCount.get(prefixProduct);
        }
        
        // If the product is not in the map, add it with a count of 1
        else {
            productCount.set(prefixProduct, 1);
        }
    }
    
    return count;
    
};