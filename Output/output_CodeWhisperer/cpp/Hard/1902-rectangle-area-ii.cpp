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
        int mod = 1000000007;
        vector<vector<int>> events;
        for (auto& rect : rectangles) {
            events.push_back({rect[0], 0, rect[1], rect[3]});
            events.push_back({rect[2], 1, rect[1], rect[3]});
        }
        sort(events.begin(), events.end());
        vector<int> active;
        int cur_x = events[0][0];
        long long ans = 0;
        for (auto& event : events) {
            int x = event[0], type = event[1], y1 = event[2], y2 = event[3];
            long long query = 0, cur_y = -1;
            for (int i = 0; i < active.size(); ++i) {
                if (i == 0 || active[i] != cur_y) {
                    if (cur_y != -1) {
                        query += active[i] - cur_y;
                    }
                    cur_y = active[i];
                }
                if (type == 1) {
                    active.erase(active.begin() + i);
                    --i;
                }
            }
            ans += query * (x - cur_x);
            cur_x = x;
            if (type == 0) {
                active.push_back(y1);
                active.push_back(y2);
                sort(active.begin(), active.end());
            }
            ans %= mod;
        }
        return ans;      
    }
};