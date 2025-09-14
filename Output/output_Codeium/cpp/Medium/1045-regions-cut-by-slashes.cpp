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
        vector<vector<int>> graph(n * 3, vector<int>(n * 3, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    graph[i * 3][j * 3 + 2] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    graph[i * 3][j * 3] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (graph[i][j] == 0) {
                    ++regions;
                    dfs(graph, i, j, n * 3);
                }
            }
        }
        return regions;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int i, int j, int size) {
        if (i < 0 || j < 0 || i >= size || j >= size || graph[i][j] == 1)
            return;
        graph[i][j] = 1;
        dfs(graph, i + 1, j, size);
        dfs(graph, i - 1, j, size);
        dfs(graph, i, j + 1, size);
        dfs(graph, i, j - 1, size);
    }

        
};