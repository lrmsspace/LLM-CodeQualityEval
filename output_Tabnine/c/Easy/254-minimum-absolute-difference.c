/**https://leetcode.com/problems/minimum-absolute-difference/ */
//Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
//Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
//	a, b are from arr
//	a < b
//	b - a equals to the minimum absolute difference of any two elements in arr
// 
//Example 1:
//Input: arr = [4,2,1,3]
//Output: [[1,2],[2,3],[3,4]]
//Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
//Example 2:
//Input: arr = [1,3,6,10,15]
//Output: [[1,3]]
//Example 3:
//Input: arr = [3,8,-10,23,19,-4,-14,27]
//Output: [[-14,-10],[19,23],[23,27]]
// 
//Constraints:
//	2 <= arr.length <= 105
//	-106 <= arr[i] <= 106
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array
    qsort(arr, arrSize, sizeof(int), compare);
    
    int minDiff = arr[1] - arr[0];
    int* result = malloc(arrSize * minDiff * sizeof(int*));
    int* columnSizes = malloc(minDiff * sizeof(int));
    int resultSize = 0;
    
    // Iterate through the sorted array and find pairs with minimum difference


    for (int i = 1; i < arrSize; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            resultSize = 0;
            columnSizes[0] = 2;
            result[0] = malloc(2 * sizeof(int));
            result[0][0] = arr[i - 1];
            result[0][1] = arr[i];
        } else if (diff == minDiff) {
            result[resultSize] = malloc(2 * sizeof(int));
            result[resultSize][0] = arr[i - 1];
            result[resultSize][1] = arr[i];
            columnSizes[resultSize++] = 2;
        }
    }
    
    *returnSize = resultSize;
    *returnColumnSizes = columnSizes;
    return result;

}