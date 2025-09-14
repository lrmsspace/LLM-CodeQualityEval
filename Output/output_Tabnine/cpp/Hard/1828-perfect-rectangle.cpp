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
        long left = LONG_MAX, right = LONG_MIN, top = LONG_MAX, bottom = LONG_MIN;
        int area = 0;
        unordered_map<pair<int, int>, int> count;
        
        for (const auto& r : rectangles) {
            left = min(left, r[0]);
            right = max(right, r[2]);
            top = min(top, r[1]);
            bottom = max(bottom, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
            
            for (int i = r[1]; i < r[3]; ++i) {
                for (int j = r[0]; j < r[2]; ++j) {
                    ++count[{j, i}];
                }
            }
        }
        
        return (area == (right - left) * (bottom - top)) && count.size() == (right - left) * (bottom - top) && all_of(count.begin(), count.end(), [](const auto& p) { return p.second == 2; });
        
    }
};