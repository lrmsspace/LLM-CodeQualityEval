/**https://leetcode.com/problems/max-chunks-to-make-sorted-ii/ */
//You are given an integer array arr.
//We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
//Return the largest number of chunks we can make to sort the array.
// 
//Example 1:
//Input: arr = [5,4,3,2,1]
//Output: 1
//Explanation:
//Splitting into two or more chunks will not return the required result.
//For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
//Example 2:
//Input: arr = [2,1,3,4,4]
//Output: 4
//Explanation:
//We can split into two chunks, such as [2, 1], [3, 4, 4].
//However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
// 
//Constraints:
//	1 <= arr.length <= 2000
//	0 <= arr[i] <= 108
int maxChunksToSorted(int* arr, int arrSize) {
    int* leftMax = (int*)malloc(arrSize * sizeof(int));
    int* rightMin = (int*)malloc(arrSize * sizeof(int));
    
    leftMax[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        leftMax[i] = fmax(leftMax[i - 1], arr[i]);
    }
    
    rightMin[arrSize - 1] = arr[arrSize - 1];
    for (int i = arrSize - 2; i >= 0; i--) {
        rightMin[i] = fmin(rightMin[i + 1], arr[i]);
    }
    
    int chunks = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (leftMax[i] <= rightMin[i + 1]) {
            chunks++;
        }
    }
    
    free(leftMax);
    free(rightMin);
    return chunks;
    
}