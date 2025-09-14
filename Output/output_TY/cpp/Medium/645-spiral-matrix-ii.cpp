/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int i = 0, j = 0;
        int k = 1;
        while(i < n && j < n){
            for(; j < n; j++){
                matrix[i][j] = k++;
            }
            j--;
            i++;
            for(; i < n; i++){
                matrix[i][j] = k++;
            }
        }
        return matrix;
    }
};