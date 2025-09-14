/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.
// 
//Example 1:
//Input: matrix = [[5,2],[1,6]], k = 1
//Output: 7
//Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
//Example 2:
//Input: matrix = [[5,2],[1,6]], k = 2
//Output: 5
//Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
//Example 3:
//Input: matrix = [[5,2],[1,6]], k = 3
//Output: 4
//Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	0 <= matrix[i][j] <= 106
//	1 <= k <= m * n
int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int* prefix = (int*)malloc((matrixSize * matrixColSize[0] + 1) * sizeof(int));
    prefix[0] = 0;
    int count = 1;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            prefix[count] = prefix[count - 1] ^ matrix[i][j];
            count++;
        }
    }
    int* arr = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        arr[i] = prefix[i];
    }
    qsort(arr, count, sizeof(int), compare);
    return arr[k - 1];
}