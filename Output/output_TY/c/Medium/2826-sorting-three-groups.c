/*
 You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
 Example 1:
 Input: nums = [2,1,3,2,1]
 Output: 3
 Explanation:
 One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
 Example 2:
 Input: nums = [1,3,2,1,3,3]
 Output: 2
 Explanation:
 One of the optimal solutions is to remove nums[1] and nums[2].
 Example 3:
 Input: nums = [2,2,2,2,3,3]
 Output: 0
 Explanation:
 nums is already non-decreasing.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 3
 Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?
*/

int minimumOperations(int* nums, int numsSize) {
    int i, j, k, cnt = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                cnt++;
            }
        }
    }
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            for (j = i + 1; j < numsSize; j++) {
                if (nums[j] != nums[i]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt <= 2;
    
}