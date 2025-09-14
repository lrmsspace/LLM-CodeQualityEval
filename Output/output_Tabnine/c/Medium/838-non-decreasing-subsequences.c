/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize the result array and column sizes
    int** result = malloc(sizeof(int*) * numsSize * (numsSize + 1) / 2);
    int* columnSizes = malloc(sizeof(int) * numsSize * (numsSize + 1) / 2);
    *returnSize = 0;
    
    // Iterate through the sorted array
    for (int i = 0; i < numsSize; i++) {
        // Initialize the size of the current subsequence
        int size = 0;
        
        // Iterate through the previous subsequences
        for (int j = 0; j < *returnSize; j++) {
            // If the current number is greater than or equal to the last number in the previous subsequence
            if (nums[i] >= result[j][size - 1]) {
                // Create a new subsequence by appending the current number
                int* newSubsequence = realloc(result[j], sizeof(int) * (size + 2));
                newSubsequence[size] = nums[i];
                newSubsequence[size + 1] = 0;
                
                // Add the new subsequence to the result array
                result[*returnSize] = newSubsequence;
                columnSizes[*returnSize] = size + 1;
                (*returnSize)++;
            }
        }
        
        // If the current number is less than the last number in the previous subsequences
        if (*returnSize > 0 && nums[i] < result[*returnSize - 1][columnSizes[*returnSize - 1] - 1]) {
            // Create a new subsequence by appending the current number
            int* newSubsequence = realloc(result[*returnSize - 1], sizeof(int) * (columnSizes[*returnSize - 1] + 2));
            newSubsequence[columnSizes[*returnSize - 1]] = nums[i];
            newSubsequence[columnSizes[*returnSize - 1] + 1] = 0;
            
            // Update the result array and column sizes
            result[*returnSize - 1] = newSubsequence;
            columnSizes[*returnSize - 1] = columnSizes[*returnSize - 1] + 1;
        }
    }
    
    // Return the result array and column sizes
    *returnColumnSizes = columnSizes;
    return result;
    
}