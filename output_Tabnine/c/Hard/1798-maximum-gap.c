/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    
    // Find the minimum and maximum values in the array
    int minValue = nums[0], maxValue = nums[0];
    for (int i = 1; i < numsSize; i++) {
        minValue = fmin(minValue, nums[i]);
        maxValue = fmax(maxValue, nums[i]);
    }
    
    // If the array contains duplicate values, return 0
    if (minValue == maxValue) return 0;
    
    // Calculate the number of buckets needed to distribute the elements
    int bucketSize = (maxValue - minValue) / (numsSize - 1);
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    
    // Initialize buckets and pointers
    int* buckets = (int*)calloc(bucketCount, sizeof(int));
    int* pointers = (int*)calloc(bucketCount, sizeof(int));
    
    // Initialize pointers to the first element of each bucket
    for (int i = 0; i < bucketCount; i++) {
        pointers[i] = -1;
    }
    
    // Distribute elements into buckets
    for (int i = 0; i < numsSize; i++) {
        int bucketIndex = (nums[i] - minValue) / bucketSize;
        if (pointers[bucketIndex] == -1) {
            pointers[bucketIndex] = i;
        } else {
            int prevIndex = pointers[bucketIndex];
            nums[prevIndex] = nums[i];
        }
    }
    
    // Find the maximum gap between successive elements in each bucket
    int maxGap = 0;
    int prevIndex = -1;
    for (int i = 0; i < bucketCount; i++) {
        if (pointers[i]!= -1) {
            if (prevIndex!= -1) {
                maxGap = fmax(maxGap, nums[pointers[i]] - nums[prevIndex]);
            }
            prevIndex = pointers[i];
        }
    }
    
    // Free the dynamically allocated memory
    free(buckets);
    free(pointers);
    
    return maxGap;
    
}