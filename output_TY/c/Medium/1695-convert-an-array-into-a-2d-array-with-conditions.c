/**https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/ */
//You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
//	The 2D array should contain only the elements of the array nums.
//	Each row in the 2D array contains distinct integers.
//	The number of rows in the 2D array should be minimal.
//Return the resulting array. If there are multiple answers, return any of them.
//Note that the 2D array can have a different number of elements on each row.
// 
//Example 1:
//Input: nums = [1,3,4,1,2,3,1]
//Output: [[1,3,4,2],[1,3],[1]]
//Explanation: We can create a 2D array that contains the following rows:
//- 1,3,4,2
//- 1,3
//- 1
//All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
//It can be shown that we cannot have less than 3 rows in a valid array.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: [[4,3,2,1]]
//Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
// 
//Constraints:
//	1 <= nums.length <= 200
//	1 <= nums[i] <= nums.length
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* a = (int*)malloc(sizeof(int) * numsSize);
    int* b = (int*)malloc(sizeof(int) * numsSize);
    int* c = (int*)malloc(sizeof(int) * numsSize);
    int*d = (int*)malloc(sizeof(int));
    int* e = (int*)malloc(sizeof(int));

    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        b[i] = 0;
    }

    for (i = 0; i < numsSize; i++) {
        c[i] = 0;
    }

    for (i= 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (a[i] == nums[j]) {
                b[j]++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (b[i] > c[i]) {
            c[i] = b[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (c[i] > 0) {
            d[0]++;
        }
    }
    *returnSize = d[0];
    *returnColumnSizes = (int*)malloc(sizeof(int) * d[0]);
    for (i = 0; i < d[0]; i++) {
        (*returnColumnSizes)[i] = c[i];
    }
    return (int**)malloc(sizeof(int*) * d[0]);
}