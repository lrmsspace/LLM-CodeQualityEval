/*
 You are given an integer array nums and an integer k.
 You are allowed to perform the following operation on each element of the array at most once:
 Add an integer in the range [-k, k] to the element.
 Return the maximum possible number of distinct elements in nums after performing the operations.
 Example 1:
 Input: nums = [1,2,2,3,3,4], k = 2
 Output: 6
 Explanation:
 nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.
 Example 2:
 Input: nums = [4,4,4,4], k = 1
 Output: 3
 Explanation:
 By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
*/
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int distinct_count = 0;
    int last_num = nums[0] - 1;  // Initialize with a value different from nums[0]

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != last_num) {
            last_num = nums[i];
            distinct_count++;
        } else {
            // Attempt to make this element distinct by adding a value in the range [-k, k]
            if (i > 0 && nums[i] - nums[i-1] <= k * 2) {
                last_num = nums[i] + k;
                distinct_count++;
            }
        }
    }
    
    return distinct_count;
}

