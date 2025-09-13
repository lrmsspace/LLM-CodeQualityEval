/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '\' is represented as '\\'.
// 
//Example 1:
//Input: grid = [" /","/ "]
//Output: 2
//Example 2:
//Input: grid = [" /","  "]
//Output: 1
//Example 3:
//Input: grid = ["/\\","\\/"]
//Output: 5
//Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 30
//	grid[i][j] is either '/', '\', or ' '.
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(3*n, vector<int>(3*n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    graph[3*i][3*j+2] = 1;
                    graph[3*i+1][3*j+1] = 1;
                    graph[3*i+2][3*j] = 1;
                } else if (grid[i][j] == '\\') {
                    graph[3*i][3*j] = 1;
                    graph[3*i+1][3*j+1] = 1;
                    graph[3*i+2][3*j+2] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 3*n; i++) {
            for (int j = 0; j < 3*n; j++) {
                if (graph[i][j] == 0) {
                    dfs(graph, i, j);
                    res++;
                }
            }
        }
        return res;        
    }
};