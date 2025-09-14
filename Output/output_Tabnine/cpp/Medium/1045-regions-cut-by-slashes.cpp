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
        vector<int> parent(4 * n * n, -1);
        vector<int> size(4 * n * n, 1);
        
        function<int(int)> find = [&](int x) {
            if (parent[x] == -1) return x;
            return parent[x] = find(parent[x]);
        };
        
        function<void(int, int, int, int)> unionSet = [&](int x, int y, int dx, int dy) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            
            parent[x] = y;
            size[y] += size[x];
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    unionSet(4 * i * n + 2 * j + 1, 4 * i * n + 2 * j, 0, 1);
                    unionSet(4 * i * n + 2 * j + 1, 4 * (i + 1) * n + 2 * j, 0, -1);
                    unionSet(4 * i * n + 2 * j + 1, 4 * i * n + 2 * (j + 1), 1, 0);
                } else if (grid[i][j] == '\\') {
                    unionSet(4 * i * n + 2 * j, 4 * i * n + 2 * j + 1, 0, 1);
                    unionSet(4 * i * n + 2 * j, 4 * (i + 1) * n + 2 * j, 0, -1);
                    unionSet(4 * i * n + 2 * j + 1, 4 * i * n + 2 * (j + 1), 1, 0);
                } else {
                    unionSet(4 * i * n + 2 * j, 4 * i * n + 2 * (j + 1), 1, 0);
                    unionSet(4 * i * n + 2 * j + 1, 4 * (i + 1) * n + 2 * (j + 1), 1, 0);
                }

                unionSet(4 * i * n + 2 * j, 4 * i * n + 2 * (j + 1), 0, 1);
                unionSet(4 * i * n + 2 * j + 1, 4 * i * n + 2 * (j + 1), 0, -1);
            }

            unionSet(4 * i * n, 4 * (i + 1) * n, 1, 0);
            unionSet(4 * i * n + 2 * n - 1, 4 * (i + 1) * n + 2 * n - 1, -1, 0);
        }
        
        int result = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (parent[i] == -1) ++result;
        }
        
        return result;
    }
};