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
int rectangleArea(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    int mod = 1000000007;
    long long result = 0;
    vector<vector<int>> events;
    for (int i = 0; i < rectanglesSize; i++) {
        events.push_back({rectangles[i][1], 1, rectangles[i][0], rectangles[i][2]});
        events.push_back({rectangles[i][3], -1, rectangles[i][0], rectangles[i][2]});
    }
    sort(events.begin(), events.end());
    set<vector<int>> active;
    int lastY = events[0][0];
    long long length = 0;
    for (int i = 0; i < events.size(); i++) {
        int y = events[i][0], type = events[i][1], x1 = events[i][2], x2 = events[i][3];
        result = (result + length * (y - lastY)) % mod;
        lastY = y;
        if (type == 1) {
            active.insert({x1, x2});
        } else {
            active.erase({x1, x2});
        }
        length = 0;
        int cur = 0;
        for (auto& seg : active) {
            cur = max(cur, seg[0]);
            length += max(0, seg[1] - cur);
            cur = max(cur, seg[1]);
        }
    }
    return result;   
}