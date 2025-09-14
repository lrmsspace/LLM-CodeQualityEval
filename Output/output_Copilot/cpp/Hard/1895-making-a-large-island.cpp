/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> size = {0, 0}; // size of each island
        int index = 2; // index of each island
        int res = 0; // result
        unordered_map<int, int> mp; // <index, size>
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    size.push_back(dfs(grid, i, j, index));
                    res = max(res, size.back());
                    mp[index++] = size.back();
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (auto& dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            st.insert(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (int i : st) {
                        sum += mp[i];
                    }
                    res = max(res, sum);
                }
            }
        }
        return res;        
    }
};