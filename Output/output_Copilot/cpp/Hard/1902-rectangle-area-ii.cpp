/**https://leetcode.com/problems/rectangle-area-ii/ */
//You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
//Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
//Return the total area. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//Output: 6
//Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
//From (1,1) to (2,2), the green and red rectangles overlap.
//From (1,0) to (2,3), all three rectangles overlap.
//Example 2:
//Input: rectangles = [[0,0,1000000000,1000000000]]
//Output: 49
//Explanation: The answer is 1018 modulo (109 + 7), which is 49.
// 
//Constraints:
//	1 <= rectangles.length <= 200
//	rectanges[i].length == 4
//	0 <= xi1, yi1, xi2, yi2 <= 109
//	xi1 <= xi2
//	yi1 <= yi2
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> xSet;
        for (auto& rec : rectangles) {
            xSet.insert(rec[0]);
            xSet.insert(rec[2]);
        }
        vector<int> xVec(xSet.begin(), xSet.end());
        unordered_map<int, int> xIdx;
        for (int i = 0; i < xVec.size(); ++i) {
            xIdx[xVec[i]] = i;
        }
        vector<vector<int>> recs;
        for (auto& rec : rectangles) {
            rec[0] = xIdx[rec[0]];
            rec[2] = xIdx[rec[2]];
            recs.push_back(rec);
        }
        sort(recs.begin(), recs.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        vector<int> yVec = {0};
        for (auto& rec : recs) {
            if (rec[1] > yVec.back()) {
                yVec.push_back(rec[1]);
            }
            if (rec[3] < yVec.back()) {
                yVec.push_back(rec[3]);
            }
        }
        long long res = 0;
        for (int i = 0; i < recs.size(); ++i) {
            long long width = xVec[recs[i][2]] - xVec[recs[i][0]];
            long long height = yVec[i + 1] - yVec[i];
            res += width * height;
            res %= 1000000007;
        }
        return res;        
    }
};