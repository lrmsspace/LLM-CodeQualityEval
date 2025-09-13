/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// 
//Example 1:
//Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
//Output: 13
//Explanation: There are two falling paths with a minimum sum as shown.
//Example 2:
//Input: matrix = [[-19,57],[-40,-5]]
//Output: -59
//Explanation: The falling path with a minimum sum is shown.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	1 <= n <= 100
//	-100 <= matrix[i][j] <= 100
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                }else{
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                    if(j > 0){
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
                    }
                    if(j < m-1){
                        dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
        
    }
};