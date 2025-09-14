/**https://leetcode.com/problems/escape-a-large-maze/ */
//There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
//Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
//Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.
// 
//Example 1:
//Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
//Output: false
//Explanation: The target square is inaccessible starting from the source square because we cannot move.
//We cannot move north or east because those squares are blocked.
//We cannot move south or west because we cannot go outside of the grid.
//Example 2:
//Input: blocked = [], source = [0,0], target = [999999,999999]
//Output: true
//Explanation: Because there are no blocked cells, it is possible to reach the target square.
// 
//Constraints:
//	0 <= blocked.length <= 200
//	blocked[i].length == 2
//	0 <= xi, yi < 106
//	source.length == target.length == 2
//	0 <= sx, sy, tx, ty < 106
//	source != target
//	It is guaranteed that source and target are not blocked.    
class Solution {
    public:
        bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
            // Convert blocked cells to a set for O(1) lookup
            unordered_set<long long> blockedSet;
            for (auto& cell : blocked) {
                // Use a hash function to represent 2D coordinates as a single long long
                long long hash = ((long long)cell[0] << 32) | cell[1];
                blockedSet.insert(hash);
            }
            
            // If there are no blocked cells, we can always reach the target
            if (blocked.empty()) return true;
            
            // The maximum area that can be enclosed by n blocked cells is roughly n²/2
            // So we need to check if we can get at least n²/2 steps away from both source and target
            int maxArea = blocked.size() * blocked.size() / 2;
            
            // Check if we can escape from source and from target
            return bfs(source, target, blockedSet, maxArea) && bfs(target, source, blockedSet, maxArea);
        }
        
    private:
        // Directions: up, right, down, left
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        const int GRID_SIZE = 1000000;
        
        // BFS to check if we can get far enough from start or reach end
        bool bfs(vector<int>& start, vector<int>& end, unordered_set<long long>& blocked, int maxArea) {
            unordered_set<long long> visited;
            queue<pair<int, int>> q;
            
            q.push({start[0], start[1]});
            visited.insert(((long long)start[0] << 32) | start[1]);
            
            while (!q.empty() && visited.size() <= maxArea) {
                auto [x, y] = q.front();
                q.pop();
                
                // If we reached the target, return true
                if (x == end[0] && y == end[1]) {
                    return true;
                }
                
                // Try all four directions
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    // Check if the new position is valid
                    if (nx < 0 || nx >= GRID_SIZE || ny < 0 || ny >= GRID_SIZE) {
                        continue;
                    }
                    
                    long long hash = ((long long)nx << 32) | ny;
                    
                    // Skip if the cell is blocked or already visited
                    if (blocked.count(hash) || visited.count(hash)) {
                        continue;
                    }
                    
                    q.push({nx, ny});
                    visited.insert(hash);
                }
            }
            
            // If we've explored more than maxArea cells, we've escaped any potential enclosure
            return visited.size() > maxArea;
        }
    };
    