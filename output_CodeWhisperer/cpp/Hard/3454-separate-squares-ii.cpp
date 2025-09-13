/*
 You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
 Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
 Answers within 10-5 of the actual answer will be accepted.
 Note: Squares may overlap. Overlapping areas should be counted only once in this version.
 Example 1:
 Input: squares = [[0,0,1],[2,2,1]]
 Output: 1.00000
 Explanation:
 Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
 Example 2:
 Input: squares = [[0,0,2],[1,1,1]]
 Output: 1.00000
 Explanation:
 Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
 Constraints:
 1 <= squares.length <= 5 * 104
 squares[i] = [xi, yi, li]
 squares[i].length == 3
 0 <= xi, yi <= 109
 1 <= li <= 109
 The total area of all the squares will not exceed 1015.
*/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({squares[i][1], squares[i][1] + squares[i][2]});
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> v2;
        for(int i = 0; i < n; i++){
            int l = squares[i][0], r = squares[i][0] + squares[i][2];
            int j = i + 1;
            while(j < n && squares[j][0] < r){
                l = min(l, squares[j][0]);
                r = max(r, squares[j][0] + squares[j][2]);
                i++;
                j++;
            }
            v2.push_back({l, r});
            i--;
        }
        sort(v2.begin(), v2.end());
        int m = v2.size();
        double ans = 0;
        for(int i = 0; i < m; i++){
            int l = v2[i].first, r = v2[i].second;
            int j = i + 1;
            while(j < m && v2[j].first < r){
                l = min(l, v2[j].first);
                r = max(r, v2[j].second);
                i++;
                j++;
            }
            double y = v[i].first;
            double area = 0;
            for(int k = 0; k < n; k++){
                if(squares[k][1] < y && squares[k][1] + squares[k][2] > y){
                    area += min(r, squares[k][0] + squares[k][2]) - max(l, squares[k][0]);
                }
            }
            ans = max(ans, area / (r - l));
            i--;
        }
        return ans;
 
    }
};