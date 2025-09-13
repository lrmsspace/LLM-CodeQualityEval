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
        vector<vector<int>> temp(m + n - 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp[i + j].push_back(mat[i][j]);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            if (i % 2 == 0) {
                for (int j = temp[i].size() - 1; j >= 0; j--) {
                    res.push_back(temp[i][j]);
                }
            } else {
                for (int j = 0; j < temp[i].size(); j++) {
                    res.push_back(temp[i][j]);
                }
            }
        }
        return res        
    }
};