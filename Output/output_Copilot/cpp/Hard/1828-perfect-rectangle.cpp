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
        unordered_set<string> s;
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN, area = 0;
        for (auto& r : rectangles) {
            x1 = min(x1, r[0]);
            y1 = min(y1, r[1]);
            x2 = max(x2, r[2]);
            y2 = max(y2, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
            string s1 = to_string(r[0]) + " " + to_string(r[1]);
            string s2 = to_string(r[0]) + " " + to_string(r[3]);
            string s3 = to_string(r[2]) + " " + to_string(r[3]);
            string s4 = to_string(r[2]) + " " + to_string(r[1]);
            if (!s.insert(s1).second) s.erase(s1);
            if (!s.insert(s2).second) s.erase(s2);
            if (!s.insert(s3).second) s.erase(s3);
            if (!s.insert(s4).second) s.erase(s4);
        }
        string ul = to_string(x1) + " " + to_string(y1);
        string ur = to_string(x2) + " " + to_string(y1);
        string ll = to_string(x1) + " " + to_string(y2);
        string lr = to_string(x2) + " " + to_string(y2);
        return s.size() == 4 && s.count(ul) && s.count(ur) && s.count(ll) && s.count(lr) && area == (x2 - x1) * (y2 - y1);        
    }
};