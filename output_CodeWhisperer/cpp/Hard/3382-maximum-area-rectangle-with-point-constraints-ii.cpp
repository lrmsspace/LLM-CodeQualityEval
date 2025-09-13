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
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            points[i][0] = xCoord[i];
            points[i][1] = yCoord[i];
        }
        sort(points.begin(), points.end());
        set<int> ySet;
        for (int i = 0; i < n; i++) {
            ySet.insert(points[i][1]);
        }
        vector<int> yVec(ySet.begin(), ySet.end());
        int m = yVec.size();
        vector<int> left(m, -1), right(m, -1);
        for (int i = 0; i < n; i++) {
            int y = points[i][1];
            int idx = lower_bound(yVec.begin(), yVec.end(), y) - yVec.begin();
            if (left[idx] == -1) {
                left[idx] = points[i][0];
            } else {
                left[idx] = min(left[idx], points[i][0]);
            }
            right[idx] = max(right[idx], points[i][0]);
        }
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            if (left[i] == -1) {
                continue;
            }
            for (int j = i + 1; j < m; j++) {
                if (left[j] == -1) {
                    continue;
                }
                if (left[j] >= right[i]) {
                    ans = max(ans, (long long) yVec[j] - yVec[i] * (right[i] - left[j]));
                }
            }
        }
        return ans == 0 ? -1 : ans;        
    }
};