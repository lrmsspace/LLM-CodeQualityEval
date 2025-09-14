/*
 You are given an integer array nums and a positive integer k. Return the sum of the maximum and minimum elements of all subarrays with at most k elements.
 Example 1:
 Input: nums = [1,2,3], k = 2
 Output: 20
 Explanation:
 The subarrays of nums with at most 2 elements are:
 Subarray
 Minimum
 Maximum
 Sum
 [1]
 1
 1
 2
 [2]
 2
 2
 4
 [3]
 3
 3
 6
 [1, 2]
 1
 2
 3
 [2, 3]
 2
 3
 5
 Final Total
 20
 The output would be 20.
 Example 2:
 Input: nums = [1,-3,1], k = 2
 Output: -6
 Explanation:
 The subarrays of nums with at most 2 elements are:
 Subarray
 Minimum
 Maximum
 Sum
 [1]
 1
 1
 2
 [-3]
 -3
 -3
 -6
 [1]
 1
 1
 2
 [1, -3]
 -3
 1
 -2
 [-3, 1]
 -3
 1
 -2
 Final Total
 -6
 The output would be -6.
 Constraints:
 1 <= nums.length <= 80000
 1 <= k <= nums.length
 -106 <= nums[i] <= 106
*/

long long minMaxSubarraySum(int* nums, int numsSize, int k) {
    int minVal = nums[0];
    int maxVal = nums[0];
    int sum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
        sum += nums[i];
        
        if (i >= k) {
            sum -= nums[i - k];
            minVal = min(minVal, nums[i - k + 1]);
            maxVal = max(maxVal, nums[i - k + 1]);
        }
        
        if (i >= k - 1) {
            sum = max(sum, maxVal - minVal);
        }
    }
    
    return sum;
    
}