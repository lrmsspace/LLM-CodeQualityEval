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
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
*/

int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    int i = 0;

    while (i < numsSize - 1) {
        // Find the adjacent pair with the minimum sum
        int minSum = nums[i] + nums[i + 1];
        int minIndex = i;

        for (int j = i + 1; j < numsSize - 1; j++) {
            int currentSum = nums[j] + nums[j + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIndex = j;
            }
        }

        // If the minimum sum pair is already non-decreasing, break
        if (nums[minIndex] <= nums[minIndex + 1]) {
            break;
        }

        // Replace the pair with their sum
        nums[minIndex] += nums[minIndex + 1];
        for (int j = minIndex + 1; j < numsSize - 1; j++) {
            nums[j] = nums[j + 1];
        }
        numsSize--;
        operations++;
    }

    return operations;
    
}