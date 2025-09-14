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
    int i = 0, j = 0, cnt = 0, neg = 0, res = 0;
    for (j = 0; j < numsSize; j++) {
        if (nums[j] == 0) {
            i = j + 1;
            cnt = 0;
            neg = 0;
        } else {
            if (nums[j] < 0) {
                neg++;
            }
            if (neg % 2 == 0) {
                res = fmax(res, j - i + 1);
            }
        }
    }
    i = numsSize - 1;
    cnt = 0;
    neg = 0;
    for (j = numsSize - 1; j >= 0; j--) {
        if (nums[j] == 0) {
            i = j - 1;
            cnt = 0;
            neg = 0;
        } else {
            if (nums[j] < 0) {
                neg++;
            }
            if (neg % 2 == 0) {
                res = fmax(res, i - j + 1);
            }
        }
    }
    return res;    
}