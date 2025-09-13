/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<pair<int, int>, int> slope_count;
            int same_points = 1;
            int max_points_on_line = 0;
            
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    same_points++;
                    continue;
                }
                
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                slope_count[{dx, dy}]++;
                max_points_on_line = max(max_points_on_line, slope_count[{dx, dy}]);
            }
            
            ans = max(ans, max_points_on_line + same_points);

            slope_count.clear();
        }
        
        return ans;
        
    }
};