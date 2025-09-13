/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;
        
        sort(points.begin(), points.end());
        
        map<pair<int, int>, int> count;
        int minArea = INT_MAX;
        
        for (int i = 0; i < n - 1; ++i) {

            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 > x2 || y1 > y2) continue;
                
                int area = abs(x1 - x2) * abs(y1 - y2);
                
                if (area < minArea) minArea = area;
                
                count[{x1, y1}]++;
                count[{x2, y2}]++;
            }
            
            for (auto& [p, c] : count) {
                if (c > 1) minArea = min(minArea, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
            
            count.clear();

            // remove points that are already covered by previous pairs
            for (int k = i + 1; k < n; ++k) {
                int x = points[k][0], y = points[k][1];
                
                if (count.find({x, y})!= count.end()) {
                    count[{x, y}]--;
                    if (count[{x, y}] == 0) count.erase({x, y});
                }
            }
        }
        
        return minArea == INT_MAX? 0 : minArea;
        
    }
};