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
    // Initialize return array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    
    // Array to track used numbers
    int* used = (int*)calloc(numsSize, sizeof(int));
    
    // Array to store current permutation
    int* perm = (int*)malloc(numsSize * sizeof(int));
    
    // Try all permutations
    int found = 0;
    
    // Helper function to check if concatenated number is divisible by k
    int check(int* arr, int size) {
        long long num = 0;
        for(int i = 0; i < size; i++) {
            long long temp = arr[i];
            long long power = 1;
            while(temp > 0) {
                temp /= 10;
                if(temp > 0) power *= 10;
            }
            num = num * power * 10 + arr[i];
        }
        return num % k == 0;
    }
    
    // Helper function for backtracking
    void backtrack(int pos) {
        if(pos == numsSize) {
            if(check(perm, numsSize)) {
                found = 1;
                *returnSize = numsSize;
                memcpy(result, perm, numsSize * sizeof(int));
            }
            return;
        }
        
        for(int i = 0; i < numsSize && !found; i++) {
            if(!used[i]) {
                used[i] = 1;
                perm[pos] = nums[i];
                backtrack(pos + 1);
                used[i] = 0;
            }
        }
    }
    
    // Sort input array to get lexicographically smallest permutation
    for(int i = 0; i < numsSize-1; i++) {
        for(int j = 0; j < numsSize-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    
    backtrack(0);
    
    free(used);
    free(perm);
    
    if(!found) {
        free(result);
        return NULL;
    }
    
    return result;
}    