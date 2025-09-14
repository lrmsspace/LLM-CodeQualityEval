/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int k = numsSize;
    int n = numsColSize[0];
    int* minHeap = (int*)malloc(sizeof(int) * k);
    int* maxHeap = (int*)malloc(sizeof(int) * k);
    int* result = (int*)malloc(sizeof(int) * 2);
    
    for(int i = 0; i < k; i++) {
        minHeap[i] = maxHeap[i] = nums[i][0];
    }
    
    *returnSize = 2;
    result[0] = minHeap[0];
    result[1] = maxHeap[0];
    
    for(int i = 0; i < k; i++) {
        if(maxHeap[i] == minHeap[i]) {
            int nextNum = INT_MAX;
            for(int j = i + 1; j < k; j++) {
                if(nums[j][0] < nextNum) {
                    nextNum = nums[j][0];
                }
            }
            maxHeap[i] = nextNum;
        }
    }
    
    while(1) {
        int minNum = INT_MAX;
        int minIndex = 0;
        
        for(int i = 0; i < k; i++) {
            if(minHeap[i] < minNum) {
                minNum = minHeap[i];
                minIndex = i;
            }
        }
        
        if(maxHeap[minIndex] - minNum < result[1] - result[0]) {
            result[0] = minNum;
            result[1] = maxHeap[minIndex];
        }
        
        if(maxHeap[minIndex] == minHeap[minIndex]) {
            int nextNum = INT_MAX;
            for(int j = minIndex + 1; j < k; j++) {
                if(nums[j][0] < nextNum) {
                    nextNum = nums[j][0];
                }
            }
            maxHeap[minIndex] = nextNum;
        }
        
        minHeap[minIndex] = nums[++minIndex][0];
        
        if(minHeap[minIndex] > maxHeap[minIndex]) {
            break;
        }
    
}
    
    return result;
    }