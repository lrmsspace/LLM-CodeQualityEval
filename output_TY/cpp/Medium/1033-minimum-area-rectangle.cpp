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
        unordered_map<int, vector<int>> m;
        for(auto p : points){
            m[p[0]].push_back(p[1]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};