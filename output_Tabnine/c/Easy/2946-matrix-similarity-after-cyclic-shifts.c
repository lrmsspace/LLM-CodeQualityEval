/*
 You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
 The following proccess happens k times:
 Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
 Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
 Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.
 Example 1:
 Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
 Output: false
 Explanation:
 In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).
 Example 2:
 Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
 Output: true
 Explanation:
 Example 3:
 Input: mat = [[2,2],[2,2]], k = 3
 Output: true
 Explanation:
 As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.
 Constraints:
 1 <= mat.length <= 25
 1 <= mat[i].length <= 25
 1 <= mat[i][j] <= 25
 1 <= k <= 50
*/

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int** copy = (int**)malloc(matSize * sizeof(int*));
    for (int i = 0; i < matSize; i++) {
        copy[i] = (int*)malloc(matColSize[i] * sizeof(int));
        memcpy(copy[i], mat[i], matColSize[i] * sizeof(int));

        // Perform cyclic shifts
        for (int j = 0; j < k; j++) {
            int temp = copy[i][0];
            for (int l = 0; l < matColSize[i] - 1; l++) {
                copy[i][l] = copy[i][l + 1];
            }
            copy[i][matColSize[i] - 1] = temp;
        }
    }
    bool result = true;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j]!= copy[i][j]) {
                result = false;
                break;
            }
        }
        if (!result) {
            break;
        }
    }
    for (int i = 0; i < matSize; i++) {
        free(copy[i]);
    }
    free(copy);
    return result;
    
}