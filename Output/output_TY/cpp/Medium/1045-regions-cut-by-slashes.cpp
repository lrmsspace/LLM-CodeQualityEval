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
        int m = n + 1;
        vector<vector<int>> uf(m * m);
        for (int i = 0; i < m * m; i++)
        {
            uf[i].resize(4);
            uf[i][0] = i;
            uf[i][1] = i;
            uf[i][2] = i;
            uf[i][3] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * m + j;
                if (grid[i][j] == ' ')
                {
                    union_(uf, idx, idx + 1);
                    union_(uf, idx, idx + m);
                }
                else if (grid[i][j] == '/')
                {
                    union_(uf, idx, idx + m - 1);
                    union_(uf, idx + 1, idx + m);
                }
                else
                {
                   union_(uf, idx, idx + m + 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            union_(uf, 0, i);
            union_(uf, m * m - 1, m * m - 1 - i);
        }
        for (int i = 1; i < m; i++)
        {
            union_(uf, i * m, 0);
            union_(uf, i * m - 1, m * m - 1);
        }
        int ans = 0;
        for (int i = 1; i < m * m; i++)
        {
            if (uf[i][0] == i)
            {
                ans++;
            }
        }
        return ans;
    }
};