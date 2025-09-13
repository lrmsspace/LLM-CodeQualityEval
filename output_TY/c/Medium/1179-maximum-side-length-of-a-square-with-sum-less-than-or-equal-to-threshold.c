/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
// 
//Example 1:
//Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
//Output: 2
//Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
//Example 2:
//Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
//Output: 0
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 300
//	0 <= mat[i][j] <= 104
//	0 <= threshold <= 105
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold){
    int i, j, k, l, sum, max = 0;
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            sum = 0;
            for (k = i; k >= 0; k--) {
                for (l = j; l >= 0; l--) {
                    sum += mat[k][l];
                    if (sum <= threshold && (i - k + 1) * (j - l + 1) > max) {
                        max = (i - k + 1) * (j - l + 1);
                    }
                }
            }
        }
    }
    return max;
}