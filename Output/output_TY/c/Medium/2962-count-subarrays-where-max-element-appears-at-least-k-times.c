/*
 You are given an integer array nums and a positive integer k.
 Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
 A subarray is a contiguous sequence of elements within an array.
 Example 1:
 Input: nums = [1,3,2,3,3], k = 2
 Output: 6
 Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
 Example 2:
 Input: nums = [1,4,2,1], k = 3
 Output: 0
 Explanation: No subarray contains the element 4 at least 3 times.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 106
 1 <= k <= 105
*/

long long countSubarrays(int* nums, int numsSize, int k) {
    int i, j, count, max_count, max_num, min_num, min_count, max_num_count, min_num_count;
    count = max_count = max_num_count = min_num_count = 0;
    for (i = 0; i < numsSize; i++) {
        max_num = max_num_count = min_num = min_num_count = 0;
        for (j = i; j < numsSize; j++) {
            if (nums[j] > max_num) {
                max_num = nums[j];
                max_num_count = 1;
            } else if (nums[j] == max_num) {
                max_num_count++;
            }
            if (nums[j] < min_num) {
                min_num = nums[j];
                min_num_count = 1;
            } else if (nums[j] == min_num)
            min_num_count++;
        }
    }
    return count;
    
}