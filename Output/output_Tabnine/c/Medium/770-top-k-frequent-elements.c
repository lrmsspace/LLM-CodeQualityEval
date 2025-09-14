/**https://leetcode.com/problems/top-k-frequent-elements/ */
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	k is in the range [1, the number of unique elements in the array].
//	It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Create a hash map to count the frequency of each number
    int* frequency = (int*)calloc(10001, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        frequency[nums[i] + 10000]++;
    }
    
    // Step 2: Create a max heap to store the numbers with their frequencies
    int* maxHeap = (int*)calloc(k, sizeof(int));
    int heapSize = 0;
    for (int i = 10000; i >= 0; i--) {
        while (frequency[i] > 0 && heapSize < k) {
            maxHeap[heapSize++] = i - 10000;
            frequency[i]--;
        }
    }
    
    // Step 3: Extract the top k elements from the max heap
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = maxHeap[i];
    }
    
    // Step 4: Free the dynamically allocated memory
    free(frequency);
    free(maxHeap);
    
    // Step 5: Return the result
    *returnSize = k;
    return result;
    
}