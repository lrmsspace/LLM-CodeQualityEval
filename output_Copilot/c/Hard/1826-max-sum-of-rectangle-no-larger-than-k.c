/**https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.
// 
//Example 1:
//Input: matrix = [[1,0,1],[0,-2,3]], k = 2
//Output: 2
//Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
//Example 2:
//Input: matrix = [[2,2,-1]], k = 3
//Output: 3
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	-100 <= matrix[i][j] <= 100
//	-105 <= k <= 105
// 
//Follow up: What if the number of rows is much larger than the number of columns?
int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize, n = matrixColSize[0];
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum[m];
        memset(sum, 0, sizeof(sum));
        for (int j = i; j < n; j++) {
            for (int l = 0; l < m; l++) {
                sum[l] += matrix[l][j];
            }
            set<int> st;
            st.insert(0);
            int s = 0;
            for (int l = 0; l < m; l++) {
                s += sum[l];
                auto it = st.lower_bound(s - k);
                if (it != st.end()) {
                    res = max(res, s - *it);
                }
                st.insert(s);
            }
        }
    }
    return res;    
}