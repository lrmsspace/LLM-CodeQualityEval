/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    // Determine the total number of elements
    int totalElements = 0;
    for (int i = 0; i < numsSize; i++) {
        totalElements += numsColSize[i];
    }

    // Initialize the result array and set the returnSize
    int* result = (int*)malloc(totalElements * sizeof(int));
    *returnSize = totalElements;

    // Use a map to store numbers according to their diagonal key
    typedef struct {
        int *data;
        int size;
        int capacity;
    } Vector;

    Vector *diagonals = (Vector *)malloc((numsSize + numsColSize[0]) * sizeof(Vector));
    int maxKey = 0;

    for (int i = 0; i < numsSize + numsColSize[0]; i++) {
        diagonals[i].data = (int *)malloc(10 * sizeof(int));
        diagonals[i].size = 0;
        diagonals[i].capacity = 10;
    }

    // Populate the diagonals
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            int key = i + j;
            if (key > maxKey) maxKey = key;
            if (diagonals[key].size == diagonals[key].capacity) {
                diagonals[key].capacity *= 2;
                diagonals[key].data = (int *)realloc(diagonals[key].data, diagonals[key].capacity * sizeof(int));
            }
            diagonals[key].data[diagonals[key].size++] = nums[i][j];
        }
    }

    // Fill the result array
    int index = 0;
    for (int k = 0; k <= maxKey; k++) {
        for (int i = diagonals[k].size - 1; i >= 0; i--) {
            result[index++] = diagonals[k].data[i];
        }
    }

    // Free allocated memory for diagonals
    for (int i = 0; i <= maxKey; i++) {
        free(diagonals[i].data);
    }
    free(diagonals);

    return result;

}