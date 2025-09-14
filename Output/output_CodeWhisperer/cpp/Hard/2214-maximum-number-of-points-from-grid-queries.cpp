/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
//	If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//	Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.
// 
//Example 1:
//Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//Output: [5,8,1]
//Explanation: The diagrams above show which cells we visit to get points for each query.
//Example 2:
//Input: grid = [[5,2,1],[1,1,2]], queries = [3]
//Output: [0]
//Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 1000
//	4 <= m * n <= 105
//	k == queries.length
//	1 <= k <= 104
//	1 <= grid[i][j], queries[i] <= 106
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        int cnt = 0;
        for (auto& v : q) {
            int val = v[0], idx = v[1];
            while (!pq.empty() && pq.top()[0] < val) {
                int i = pq.top()[1], j = pq.top()[2];
                pq.pop();
                if (visited[i][j]) continue;
                visited[i][j] = true;
                cnt++;
                if (i > 0) pq.push({grid[i-1][j], i-1, j});
                if (i < m-1) pq.push({grid[i+1][j], i+1, j});
                if (j > 0) pq.push({grid[i][j-1], i, j-1});
                if (j < n-1) pq.push({grid[i][j+1], i, j+1});
            }
            res.push_back(cnt);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[q[i][1]] = res[i];
        }
        return ans;    
    }
};