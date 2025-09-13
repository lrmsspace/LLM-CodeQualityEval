/**https://leetcode.com/problems/self-crossing/ */
//You are given an array of integers distance.
//You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
//Return true if your path crosses itself or false if it does not.
// 
//Example 1:
//Input: distance = [2,1,1,2]
//Output: true
//Explanation: The path crosses itself at the point (0, 1).
//Example 2:
//Input: distance = [1,2,3,4]
//Output: false
//Explanation: The path does not cross itself at any point.
//Example 3:
//Input: distance = [1,1,1,2,1]
//Output: true
//Explanation: The path crosses itself at the point (0, 0).
// 
//Constraints:
//	1 <= distance.length <= 105
//	1 <= distance[i] <= 105
bool isSelfCrossing(int* distance, int distanceSize) {
    int x = 0, y = 0, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0}, dir = 0;
    int vis[100005][100005] = {};
    vis[50000][50000] = 1;
    for (int i = 0; i < distanceSize; ++i) {
        int d = (dir + (distance[i] & 3)) & 3;
        for (int j = 0; j < distance[i]; ++j) {
            x += dx[d];
            y += dy[d];
            if (vis[x + 50000][y + 50000]) return true;
            vis[x + 50000][y + 50000] = 1;
        }
        dir = (dir + 1) & 3;
    }
    return false;
}