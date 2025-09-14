/**https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/ */
//Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
//A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
//Return the maximum length of a subarray with positive product.
// 
//Example 1:
//Input: nums = [1,-2,-3,4]
//Output: 4
//Explanation: The array nums already has a positive product of 24.
//Example 2:
//Input: nums = [0,1,-2,-3,-4]
//Output: 3
//Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
//Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
//Example 3:
//Input: nums = [-1,-2,-3,0,1]
//Output: 2
//Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
int getMaxLen(int* nums, int numsSize) {
    int* left = malloc(numsSize * sizeof(int));
    int* right = malloc(numsSize * sizeof(int));
    memset(left, 0, numsSize * sizeof(int));
    memset(right, 0, numsSize * sizeof(int));
    
    int maxLen = 0;
    int prod = 1;
    for (int i = 0; i < numsSize; i++) {
        prod *= nums[i];
        left[i] = (prod == 0)? 0 : left[i - 1] + 1;
        maxLen = fmax(maxLen, left[i]);
    }
    
    prod = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        prod *= nums[i];
        right[i] = (prod == 0)? 0 : right[i + 1] + 1;
        maxLen = fmax(maxLen, right[i] + left[i] - 1);
    }
    
    free(left);
    free(right);
    return maxLen;
    
}