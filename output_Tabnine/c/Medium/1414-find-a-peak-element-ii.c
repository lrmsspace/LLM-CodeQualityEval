/**https://leetcode.com/problems/find-a-peak-element-ii/ */
//A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
//Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
//You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
//You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
// 
//Example 1:
//Input: mat = [[1,4],[3,2]]
//Output: [0,1]
//Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
//Example 2:
//Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
//Output: [1,1]
//Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 500
//	1 <= mat[i][j] <= 105
//	No two adjacent cells are equal.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize, n = matColSize[0];
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // Binary search to find the peak element
    int left = 0, right = m * n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int midRow = mid / n, midCol = mid % n;
        
        if (mat[midRow][midCol] > mat[midRow][(midCol + 1) % n] &&
            mat[midRow][midCol] > mat[midRow][(midCol - 1 + n) % n] &&
            mat[midRow][midCol] > mat[(midRow + 1) % m][midCol] &&
            mat[midRow][midCol] > mat[(midRow - 1 + m
            ) % m][midCol]) {
            result[0] = midRow;
            result[1] = midCol;
            return result;
        } else if (mat[midRow][midCol] < mat[midRow][(midCol + 1) % n] &&
        mat[midRow][midCol] < mat[midRow][(midCol - 1 + n) % n] &&
        mat[midRow][midCol] < mat[(midRow + 1) % m][midCol] &&
        mat[midRow][midCol] < mat[(midRow - 1 + m) % m][midCol]) {
            left = mid + 1;
        } else {
            right = mid;
        }
        // Optimization: If the current element is the leftmost or rightmost column, only search in the same row
        if (midCol == 0 || midCol == n - 1) {
            left = mid + 1;
        }
    }
    
    result[0] = left / n;
    result[1] = left % n;
    return result;
}