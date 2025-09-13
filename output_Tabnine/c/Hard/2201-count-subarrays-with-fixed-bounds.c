/**https://leetcode.com/problems/count-subarrays-with-fixed-bounds/ */
//You are given an integer array nums and two integers minK and maxK.
//A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//	The minimum value in the subarray is equal to minK.
//	The maximum value in the subarray is equal to maxK.
//Return the number of fixed-bound subarrays.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
//Output: 2
//Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
//Example 2:
//Input: nums = [1,1,1,1], minK = 1, maxK = 1
//Output: 10
//Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i], minK, maxK <= 106
long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long result = 0;
    int left = 0, right = 0;
    int minValue = nums[0];
    int maxValue = nums[0];
    
    while (right < numsSize) {
        if (nums[right] < minK) {
            minValue = nums[right];
            left = right;
        } else if (nums[right] > maxK) {
            maxValue = nums[right];
            left = right;
        } else {
            result += right - left + 1;
            minValue = min(minValue, nums[right]);
            maxValue = max(maxValue, nums[right]);
        }
        right++;
    }
    
    return result;
    
}