/**https://leetcode.com/problems/perfect-rectangle/ */
//Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
//Return true if all the rectangles together form an exact cover of a rectangular region.
// 
//Example 1:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
//Output: true
//Explanation: All 5 rectangles together form an exact cover of a rectangular region.
//Example 2:
//Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
//Output: false
//Explanation: Because there is a gap between the two rectangular regions.
//Example 3:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
//Output: false
//Explanation: Because two of the rectangles overlap with each other.
// 
//Constraints:
//	1 <= rectangles.length <= 2 * 104
//	rectangles[i].length == 4
//	-105 <= xi < ai <= 105
//	-105 <= yi < bi <= 105
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        long long area = 0;
        unordered_map<long long, int> m;
        for (auto& r : rectangles) {
            x1 = min(x1, r[0]);
            y1 = min(y1, r[1]);
            x2 = max(x2, r[2]);
            y2 = max(y2, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
            m[r[0] * 20001 + r[1]]++;
        }
        m[x1 * 20001 + y1]++;
        m[x2 * 20001 + y2]++;
        return area == (x2 - x1) * (y2 - y1) && m[x1 * 20001 + y1] == 1 && m[x2 * 20001 + y2] == 1 && m[x1 * 20001 + y2] == 1 && m[x2 * 20001 + y1] == 1 && m.size() == 4;
    }
};