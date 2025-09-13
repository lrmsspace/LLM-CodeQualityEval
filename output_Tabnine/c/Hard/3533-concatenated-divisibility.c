/*
 You are given an array of positive integers nums and a positive integer k.
 A permutation of nums is said to form a divisible concatenation if, when you concatenate the decimal representations of the numbers in the order specified by the permutation, the resulting number is divisible by k.
 Return the lexicographically smallest permutation (when considered as a list of integers) that forms a divisible concatenation. If no such permutation exists, return an empty list.
 Example 1:
 Input: nums = [3,12,45], k = 5
 Output: [3,12,45]
 Explanation:
 Permutation
 Concatenated Value
 Divisible by 5
 [3, 12, 45]
 31245
 Yes
 [3, 45, 12]
 34512
 No
 [12, 3, 45]
 12345
 Yes
 [12, 45, 3]
 12453
 No
 [45, 3, 12]
 45312
 No
 [45, 12, 3]
 45123
 No
 The lexicographically smallest permutation that forms a divisible concatenation is [3,12,45].
 Example 2:
 Input: nums = [10,5], k = 10
 Output: [5,10]
 Explanation:
 Permutation
 Concatenated Value
 Divisible by 10
 [5, 10]
 510
 Yes
 [10, 5]
 105
 No
 The lexicographically smallest permutation that forms a divisible concatenation is [5,10].
 Example 3:
 Input: nums = [1,2,3], k = 5
 Output: []
 Explanation:
 Since no permutation of nums forms a valid divisible concatenation, return an empty list.
 Constraints:
 1 <= nums.length <= 13
 1 <= nums[i] <= 105
 1 <= k <= 100
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* concatenatedDivisibility(int* nums, int numsSize, int k, int* returnSize) {

    // Step 1: Sort the given array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Create a string representation of the sorted array
    char* str = malloc(numsSize * 10 + 1); // Assuming each number has at most 10 digits
    str[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        sprintf(str + strlen(str), "%d", nums[i]);
    }
    
    // Step 3: Initialize a list to store the permutations
    int* permutations = malloc(factorial(numsSize) * sizeof(int));
    int permIndex = 0;
    
    // Step 4: Generate all permutations of the given array
    generatePermutations(nums, numsSize, 0, permutations, &permIndex);
    
    // Step 5: Find the lexicographically smallest permutation that forms a divisible concatenation
    int* smallestDivisible = NULL;
    for (int i = 0; i < permIndex; i++) {
        int concatenated = 0;
        for (int j = 0; j < numsSize; j++) {
            concatenated = concatenated * 10 + permutations[i * numsSize + j];
        }
        
        if (concatenated % k == 0) {
            if (smallestDivisible == NULL || compare(smallestDivisible, permutations + i * numsSize) > 0) {
                smallestDivisible = permutations + i * numsSize;
            }
        }
    }
    
    // Step 6: Return the lexicographically smallest permutation that forms a divisible concatenation
    *returnSize = smallestDivisible == NULL? 0 : numsSize;
    return smallestDivisible;   
    
}