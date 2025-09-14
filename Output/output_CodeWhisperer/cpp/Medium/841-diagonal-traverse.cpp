/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int i = 0, j = 0;
        bool up = true;
        while (i < m && j < n) {
            res.push_back(mat[i][j]);
            if (up) {
                if (j == n - 1) {
                    i++;
                    up = false;
                } else if (i == 0) {
                    j++;
                    up = false;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == m - 1) {
                    j++;
                    up = true;
                } else if (j == 0) {
                    i++;
                    up = true;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return res;      
    }
};