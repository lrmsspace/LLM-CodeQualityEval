/*
 You are given an integer array nums. In one operation, you can select a subarray and replace it with a single element equal to its maximum value.
 Return the maximum possible size of the array after performing zero or more operations such that the resulting array is non-decreasing.
 Example 1:
 Input: nums = [4,2,5,3,5]
 Output: 3
 Explanation:
 One way to achieve the maximum size is:
 Replace subarray nums[1..2] = [2, 5] with 5 → [4, 5, 3, 5].
 Replace subarray nums[2..3] = [3, 5] with 5 → [4, 5, 5].
 The final array [4, 5, 5] is non-decreasing with size 3.
 Example 2:
 Input: nums = [1,2,3]
 Output: 3
 Explanation:
 No operation is needed as the array [1,2,3] is already non-decreasing.
 Constraints:
 1 <= nums.length <= 2 * 105
 1 <= nums[i] <= 2 * 105
*/

int maximumPossibleSize(int* nums, int numsSize) {
    int max_val = nums[0];
    int max_count = 1;
    int curr_val = nums[0];
    int curr_count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == curr_val) {
            curr_count++;
        } else {
            max_val = max(max_val, curr_val);
            max_count = max(max_count, curr_count);
            curr_val = nums[i];
            curr_count = 1;
        }
    }
    
    max_val = max(max_val, curr_val);
    max_count = max(max_count, curr_count);
    
    return numsSize - max_count;
    
}