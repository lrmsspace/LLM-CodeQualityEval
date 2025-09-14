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
        unordered_set<string> blockSet;
        for (auto &block : blocked) {
            blockSet.emplace(to_string(block[0]) + "," + to_string(block[1]));
        }
        queue<pair<int, int>> q;
        q.push({source[0], source[1]});
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int step = 0;
        while (!q.empty() && step < blocked.size() + 1) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x == target[0] && y == target[1]) return true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < 1e6 && ny >= 0 && ny < 1e6 && 
                    !blockSet.count(to_string(nx) + "," + to_string(ny))) {
                    q.push({nx, ny});
                    blockSet.insert(to_string(nx) + "," + to_string(ny));
                }
            }
            ++step;
        }
        return false;
    }
};