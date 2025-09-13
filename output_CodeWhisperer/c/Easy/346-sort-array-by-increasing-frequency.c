/**https://leetcode.com/problems/sort-array-by-increasing-frequency/ */
//Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//Return the sorted array.
// 
//Example 1:
//Input: nums = [1,1,2,2,2,3]
//Output: [3,1,1,2,2,2]
//Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
//Example 2:
//Input: nums = [2,3,1,3,2]
//Output: [1,3,3,2,2]
//Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
//Example 3:
//Input: nums = [-1,1,-6,4,5,-6,1,4,1]
//Output: [5,-1,4,4,-6,-6,1,1,1]
// 
//Constraints:
//	1 <= nums.length <= 100
//	-100 <= nums[i] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int* freq = (int*)calloc(201, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 100]++;
    }
    int* freq2 = (int*)calloc(201, sizeof(int));
    for (int i = 0; i < 201; i++) {
        freq2[freq[i]]++;
    }
    int index = 0;
    for (int i = 200; i >= 0; i--) {
        if (freq2[i] > 0) {
            for (int j = 0; j < 201; j++) {
                if (freq[j] == i) {
                    for (int k = 0; k < freq[j]; k++) {
                        result[index++] = j - 100;
                    }
                }
            }
        }
    }
    free(freq);
    free(freq2);
    return result;
    
}