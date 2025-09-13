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
        int n = rectangles.size();
        int left = INT_MAX, right = INT_MIN, top = INT_MIN, bottom = INT_MAX;
        int area = 0;
        set<pair<int, int>> s;
        for (auto& rect : rectangles) {
            left = min(left, rect[0]);
            bottom = min(bottom, rect[1]);
            right = max(right, rect[2]);
            top = max(top, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            s.insert({rect[0], rect[1]});
            s.insert({rect[0], rect[3]});
            s.insert({rect[2], rect[1]});
            s.insert({rect[2], rect[3]});
        }
        if (s.size() != 4 || !s.count({left, bottom}) || !s.count({left, top}) || !s.count({right, bottom}) || !s.count({right, top})) {
            return false;
        }
        return area == (right - left) * (top - bottom);      
    }
};