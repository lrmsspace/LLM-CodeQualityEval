/*
 Given an array nums, you can perform the following operation any number of times:
 Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
 Replace the pair with their sum.
 Return the minimum number of operations needed to make the array non-decreasing.
 An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
 Example 1:
 Input: nums = [5,2,3,1]
 Output: 2
 Explanation:
 The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
 The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
 The array nums became non-decreasing in two operations.
 Example 2:
 Input: nums = [1,2,2]
 Output: 0
 Explanation:
 The array nums is already sorted.
 Constraints:
 1 <= nums.length <= 50
 -1000 <= nums[i] <= 1000
*/

int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    int i, j;

    // Continue until the array is non-decreasing
    while (1) {
        int found = 0; // Flag to check if any pair was removed
        for (i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                // Find the leftmost pair with minimum sum
                int minSum = nums[i] + nums[i + 1];
                j = i;
                while (j < numsSize - 1 && nums[j] + nums[j + 1] <= minSum) {
                    minSum = nums[j] + nums[j + 1];
                    j++;
                }
                // Replace the pair with their sum
                nums[i] += nums[i + 1];
                for (int k = i + 1; k < numsSize - 1; k++) {
                    nums[k] = nums[k + 1];
                }
                numsSize--; // Reduce the size of the array
                operations++;
                found = 1; // Mark that we found a pair to remove
                break; // Restart from the beginning
            }
        }
        if (!found) {
            break; // No more pairs to remove, exit the loop
        }
    }

    return operations;
    
}