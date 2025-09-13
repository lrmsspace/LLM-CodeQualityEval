/**https://leetcode.com/problems/self-crossing/ */
//You are given an array of integers distance.
//You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
//Return true if your path crosses itself or false if it does not.
// 
//Example 1:
//Input: distance = [2,1,1,2]
//Output: true
//Explanation: The path crosses itself at the point (0, 1).
//Example 2:
//Input: distance = [1,2,3,4]
//Output: false
//Explanation: The path does not cross itself at any point.
//Example 3:
//Input: distance = [1,1,1,2,1]
//Output: true
//Explanation: The path crosses itself at the point (0, 0).
// 
//Constraints:
//	1 <= distance.length <= 105
//	1 <= distance[i] <= 105
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int x = 0, y = 0;
        vector<pair<int, int>> path;
        for (int i = 0; i < distance.size(); ++i) {
            int dx = 0, dy = 0;
            if (i % 4 == 0) dy = distance[i];
            if (i % 4 == 1) dx = -distance[i];
            if (i % 4 == 2) dy = -distance[i];
            if (i % 4 == 3) dx = distance[i];
            int nx = x + dx, ny = y + dy;
            for (const auto& p : path) {
                if (nx == p.first && max(y, ny) >= p.second.first && min(y, ny) <= p.second.second) return true;
            }
            path.push_back({nx, {min(y, ny), max(y, ny)}});
            x = nx;
            y = ny;
        }
        return false;
    }
};