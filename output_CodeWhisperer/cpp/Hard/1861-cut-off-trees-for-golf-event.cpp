/**https://leetcode.com/problems/cut-off-trees-for-golf-event/ */
//You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
//	0 means the cell cannot be walked through.
//	1 represents an empty cell that can be walked through.
//	A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
//In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
//You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
//Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
//Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.
// 
//Example 1:
//Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
//Output: 6
//Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
//Example 2:
//Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
//Output: -1
//Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
//Example 3:
//Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
//Output: 6
//Explanation: You can follow the same path as Example 1 to cut off all the trees.
//Note that you can cut off the first tree at (0, 0) before making any steps.
// 
//Constraints:
//	m == forest.length
//	n == forest[i].length
//	1 <= m, n <= 50
//	0 <= forest[i][j] <= 109
//	Heights of all trees are distinct.  
class Solution {
    public:
        int cutOffTree(vector<vector<int>>& forest) {
            if (forest.empty() || forest[0].empty()) return 0;
            int m = forest.size(), n = forest[0].size();
            
            // If the starting position is blocked, we can't cut any trees
            if (forest[0][0] == 0) return -1;
            
            // Collect all trees and sort them by height
            vector<vector<int>> trees;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (forest[i][j] > 1) {
                        trees.push_back({forest[i][j], i, j});
                    }
                }
            }
            
            sort(trees.begin(), trees.end());
            
            // Start from (0, 0) and visit each tree in order
            int totalSteps = 0;
            int currRow = 0, currCol = 0;
            
            for (const auto& tree : trees) {
                int steps = bfs(forest, currRow, currCol, tree[1], tree[2], m, n);
                if (steps == -1) return -1; // If we can't reach a tree, return -1
                
                totalSteps += steps;
                currRow = tree[1];
                currCol = tree[2];
                
                // Cut off the tree (set its value to 1)
                forest[currRow][currCol] = 1;
            }
            
            return totalSteps;
        }
        
    private:
        // BFS to find the shortest path from (startRow, startCol) to (endRow, endCol)
        int bfs(const vector<vector<int>>& forest, int startRow, int startCol, int endRow, int endCol, int m, int n) {
            // If start and end are the same, no steps needed
            if (startRow == endRow && startCol == endCol) return 0;
            
            // Direction vectors for the four possible moves (up, right, down, left)
            vector<int> dr = {-1, 0, 1, 0};
            vector<int> dc = {0, 1, 0, -1};
            
            // Queue for BFS
            queue<pair<int, int>> q;
            q.push({startRow, startCol});
            
            // Visited array to avoid revisiting cells
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[startRow][startCol] = true;
            
            int steps = 0;
            
            while (!q.empty()) {
                int size = q.size();
                steps++;
                
                for (int i = 0; i < size; i++) {
                    auto [row, col] = q.front();
                    q.pop();
                    
                    // Try all four directions
                    for (int j = 0; j < 4; j++) {
                        int newRow = row + dr[j];
                        int newCol = col + dc[j];
                        
                        // Check if the new position is valid
                        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                            !visited[newRow][newCol] && forest[newRow][newCol] > 0) {
                            
                            // If we reached the target, return the steps
                            if (newRow == endRow && newCol == endCol) {
                                return steps;
                            }
                            
                            // Mark as visited and add to queue
                            visited[newRow][newCol] = true;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
            
            // If we can't reach the target
            return -1;
        }
    };
    