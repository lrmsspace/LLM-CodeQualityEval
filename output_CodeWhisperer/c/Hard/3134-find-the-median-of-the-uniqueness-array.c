/*
 You are given an integer array nums. The uniqueness array of nums is the sorted array that contains the number of distinct elements of all the subarrays of nums. In other words, it is a sorted array consisting of distinct(nums[i..j]), for all 0 <= i <= j < nums.length.
 Here, distinct(nums[i..j]) denotes the number of distinct elements in the subarray that starts at index i and ends at index j.
 Return the median of the uniqueness array of nums.
 Note that the median of an array is defined as the middle element of the array when it is sorted in non-decreasing order. If there are two choices for a median, the smaller of the two values is taken.
 Example 1:
 Input: nums = [1,2,3]
 Output: 1
 Explanation:
 The uniqueness array of nums is [distinct(nums[0..0]), distinct(nums[1..1]), distinct(nums[2..2]), distinct(nums[0..1]), distinct(nums[1..2]), distinct(nums[0..2])] which is equal to [1, 1, 1, 2, 2, 3]. The uniqueness array has a median of 1. Therefore, the answer is 1.
 Example 2:
 Input: nums = [3,4,3,4,5]
 Output: 2
 Explanation:
 The uniqueness array of nums is [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3]. The uniqueness array has a median of 2. Therefore, the answer is 2.
 Example 3:
 Input: nums = [4,3,5,4]
 Output: 2
 Explanation:
 The uniqueness array of nums is [1, 1, 1, 1, 2, 2, 2, 3, 3, 3]. The uniqueness array has a median of 2. Therefore, the answer is 2.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

int medianOfUniquenessArray(int* nums, int numsSize) {
    // Calculate total number of subarrays
    int totalSubarrays = (numsSize * (numsSize + 1)) / 2;
    
    // Array to store uniqueness values
    int* uniquenessArray = (int*)malloc(totalSubarrays * sizeof(int));
    int uniquenessIndex = 0;
    
    // For each possible subarray
    for(int i = 0; i < numsSize; i++) {
        // Hash table to track unique elements
        int* seen = (int*)calloc(100001, sizeof(int));
        int uniqueCount = 0;
        
        for(int j = i; j < numsSize; j++) {
            // If element not seen before, increment unique count
            if(seen[nums[j]] == 0) {
                uniqueCount++;
            }
            seen[nums[j]]++;
            
            // Add unique count for this subarray to uniqueness array
            uniquenessArray[uniquenessIndex++] = uniqueCount;
        }
        free(seen);
    }
    
    // Sort uniqueness array
    for(int i = 0; i < totalSubarrays - 1; i++) {
        for(int j = 0; j < totalSubarrays - i - 1; j++) {
            if(uniquenessArray[j] > uniquenessArray[j+1]) {
                int temp = uniquenessArray[j];
                uniquenessArray[j] = uniquenessArray[j+1];
                uniquenessArray[j+1] = temp;
            }
        }
    }
    
    // Get median
    int median = uniquenessArray[(totalSubarrays-1)/2];
    
    free(uniquenessArray);
    return median;
}            
