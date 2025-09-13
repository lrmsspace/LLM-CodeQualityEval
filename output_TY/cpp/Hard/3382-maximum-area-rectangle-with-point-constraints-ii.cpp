/*
 There are n points on an infinite plane. You are given two integer arrays xCoord and yCoord where (xCoord[i], yCoord[i]) represents the coordinates of the ith point.
 Your task is to find the maximum area of a rectangle that:
 Can be formed using four of these points as its corners.
 Does not contain any other point inside or on its border.
 Has its edges parallel to the axes.
 Return the maximum area that you can obtain or -1 if no such rectangle is possible.
 Example 1:
 Input: xCoord = [1,1,3,3], yCoord = [1,3,1,3]
 Output: 4
 Explanation:
 We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
 Example 2:
 Input: xCoord = [1,1,3,3,2], yCoord = [1,3,1,3,2]
 Output: -1
 Explanation:
 There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
 Example 3:
 Input: xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]
 Output: 2
 Explanation:
 The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
 Constraints:
 1 <= xCoord.length == yCoord.length <= 2 * 105
 0 <= xCoord[i], yCoord[i] <= 8 * 107
 All the given points are unique.
*/

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        
        int n = xCoord.size();
        vector<pair<int, int>> points;
        for(int i = 0; i < n; i++){
            points.push_back({xCoord[i], yCoord[i]});
        }
        sort(points.begin(), points.end());
        
        vector<int> xCoordSorted;
        vector<int> yCoordSorted;
        for(int i = 0; i < n; i++){
            xCoordSorted.push_back(points[i].first);
            yCoordSorted.push_back(points[i].second);
        }
        
        int m = xCoordSorted.size();
        int n = yCoordSorted.size();
        vector<vector<int>> xCoordCount(m, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                xCoordCount[i][j] = upper_bound(xCoordSorted.begin() + i, xCoordSorted.begin() + j + 1, xCoordSorted[j] + 1) - (xCoordSorted.begin() + i);
            }
        }
        vector<vector<int>> yCoordCount(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                yCoordCount[i][j] = upper_bound(yCoordSorted.begin() + i, yCoordSorted.begin() + j + 1, yCoordSorted[j] + 1) - (yCoordSorted.begin() + i);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int xCoordCount = xCoordCount[i][j];
                int yCoordCount = yCoordCount[i][j];
                int xCoord = xCoordSorted[j] - xCoordSorted[i] + 1;
                int yCoord = yCoordSorted[j] - yCoordSorted[i] + 1;
                ans = max(ans, xCoord * yCoord);
            }
        }
        return ans;

    }
};