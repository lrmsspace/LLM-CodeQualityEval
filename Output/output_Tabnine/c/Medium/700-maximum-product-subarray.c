/**https://leetcode.com/problems/maximum-product-subarray/ */
//Given an integer array nums, find a subarray that has the largest product, and return the product.
//The test cases are generated so that the answer will fit in a 32-bit integer.
// 
//Example 1:
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-10 <= nums[i] <= 10
//	The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
int maxProduct(int* nums, int numsSize) {
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int max_product = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        int temp = max_so_far;
        max_so_far = fmax(nums[i], fmax(nums[i] * max_so_far, nums[i] * min_so_far));
        min_so_far = fmin(nums[i], fmin(nums[i] * temp, nums[i] * min_so_far));
        
        max_product = fmax(max_product, max_so_far);
    }
    
    return max_product;
    
}