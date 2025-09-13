/**https://leetcode.com/problems/sort-array-by-parity-ii/ */
//Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
//Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
//Return any answer array that satisfies this condition.
// 
//Example 1:
//Input: nums = [4,2,5,7]
//Output: [4,5,2,7]
//Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
//Example 2:
//Input: nums = [2,3]
//Output: [2,3]
// 
//Constraints:
//	2 <= nums.length <= 2 * 104
//	nums.length is even.
//	Half of the integers in nums are even.
//	0 <= nums[i] <= 1000
// 
//Follow Up: Could you solve it in-place?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    // Create two pointers, one for odd indices and one for even indices
    int left = 0, right = numsSize - 1;
    while (left < right) {
        // If the current number at the left index is odd
        if (nums[left] % 2!= 0) {
            // Find the first even number to the right of the left index
            int j = left + 1;
            while (j < numsSize && nums[j] % 2 == 1) {
                j++;
            }
            // Swap the current odd number with the first even number found
            if (j < numsSize) {
                int temp = nums[left];
                nums[left] = nums[j];
                nums[j] = temp;
            } else {
                // No even number found, return an empty array
                *returnSize = 0;
                return NULL;
            }
        } else {
            left++;
        }
        
        // If the current number at the right index is even
        if (nums[right] % 2 == 0) {
            // Find the first odd number to the left of the right index
            int j = right - 1;
            while (j >= 0 && nums[j] % 2 == 0) {
                j--;
            }
            // Swap the current even number with the first odd number found
            if (j >= 0) {
                int temp = nums[right];
                nums[right] = nums[j];
                nums[j] = temp;
            } else {
                // No odd number found, return an empty array
                *returnSize = 0;
                return NULL;
            }
        } else {
            right--;
        }
    }
    
    // Return the sorted array
    *returnSize = numsSize;
    return nums;
}