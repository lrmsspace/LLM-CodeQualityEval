/**https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/ */
//Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
//A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
//Note that points on the edge of a vertical area are not considered included in the area.
// 
//Example 1:
//​
//Input: points = [[8,7],[9,9],[7,4],[9,7]]
//Output: 1
//Explanation: Both the red and the blue area are optimal.
//Example 2:
//Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
//Output: 3
// 
//Constraints:
//	n == points.length
//	2 <= n <= 105
//	points[i].length == 2
//	0 <= xi, yi <= 109
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        map<int, vector<int>> x_to_points;
        for (const auto& point : points) {
            x_to_points[point[0]].push_back(point[1]);
        }
        
        int max_width = 0;
        for (const auto& [x, points_on_x] : x_to_points) {
            sort(points_on_x.begin(), points_on_x.end());
            int width = points_on_x.back() - points_on_x[0];
            max_width = max(max_width, width);
        }
        
        return max_width;
        
    }
};