/**https://leetcode.com/problems/path-with-minimum-effort/ */
//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
// 
//Example 1:
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
//Output: 2
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
//This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//Example 2:
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
//Output: 1
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
//Example 3:
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//Output: 0
//Explanation: This route does not require any effort.
// 
//Constraints:
//	rows == heights.length
//	columns == heights[i].length
//	1 <= rows, columns <= 100
//	1 <= heights[i][j] <= 106
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));
        visited[0][0] = 0;
        
        while (!pq.empty()) {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }
        
        for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                continue;
            }
            
            int newEffort = max(effort, abs(heights[row][col] - heights[newRow][newCol]));
            
            if (newEffort < visited[newRow][newCol]) {
                visited[newRow][newCol] = newEffort;
                pq.push({newEffort, {newRow, newCol}});
            }
        }

        }
        
        return -1; // This should never happen, but we return -1 to indicate an error.
        
    }
};