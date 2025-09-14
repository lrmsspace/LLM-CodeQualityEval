/**https://leetcode.com/problems/first-completely-painted-row-or-column/ */
//You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
//Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
//Return the smallest index i at which either a row or a column will be completely painted in mat.
// 
//Example 1:
//Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
//Output: 2
//Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
//Example 2:
//Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
//Output: 3
//Explanation: The second column becomes fully painted at arr[3].
// 
//Constraints:
//	m == mat.length
//	n = mat[i].length
//	arr.length == m * n
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= arr[i], mat[r][c] <= m * n
//	All the integers of arr are unique.
//	All the integers of mat are unique.
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowSums(m, 0), colSums(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = arr[mat[i][j] - 1];
                rowSums[i] += mat[i][j];
                colSums[j] += mat[i][j];
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (rowSums[i] == m * n) {
                return i;
            }
        }
        
        for (int j = 0; j < n; ++j) {
            if (colSums[j] == m * n) {
                return j;
            }
        }
        
        return -1; // No completely painted row or column found
        
    }
};