/**https://leetcode.com/problems/rank-transform-of-a-matrix/ */
//Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].
//The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:
//	The rank is an integer starting from 1.
//	If two elements p and q are in the same row or column, then:
//	
//		If p < q then rank(p) < rank(q)
//		If p == q then rank(p) == rank(q)
//		If p > q then rank(p) > rank(q)
//	
//	
//	The rank should be as small as possible.
//The test cases are generated so that answer is unique under the given rules.
// 
//Example 1:
//Input: matrix = [[1,2],[3,4]]
//Output: [[1,2],[2,3]]
//Explanation:
//The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
//The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0][0] is rank 1.
//The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0][0] is rank 1.
//The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.
//Example 2:
//Input: matrix = [[7,7],[7,7]]
//Output: [[1,1],[1,1]]
//Example 3:
//Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
//Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 500
//	-109 <= matrix[row][col] <= 109
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rank(m + n, 0);
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[matrix[i][j]].push_back({i, j});
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            vector<int> parent(m + n, 0);
            iota(parent.begin(), parent.end(), 0);
            vector<int> rank2 = rank;
            for (auto [i, j] : it->second) {
                int p1 = findParent(parent, i), p2 = findParent(parent, j + m);
                parent[p1] = p2;
                rank2[p2] = max(rank2[p1], rank2[p2]);
            }
            for (auto [i, j] : it->second) {
                rank[i] = rank[j + m] = matrix[i][j] = rank2[findParent(parent, i)] + 1;
            }
        }
        return matrix;        
    }
};