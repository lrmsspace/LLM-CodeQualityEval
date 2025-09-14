/**https://leetcode.com/problems/path-crossing/ */
//Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
//Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
// 
//Example 1:
//Input: path = "NES"
//Output: false 
//Explanation: Notice that the path doesn't cross any point more than once.
//Example 2:
//Input: path = "NESWW"
//Output: true
//Explanation: Notice that the path visits the origin twice.
// 
//Constraints:
//	1 <= path.length <= 104
//	path[i] is either 'N', 'S', 'E', or 'W'.
bool isPathCrossing(char* path) {
    int x = 0, y = 0;
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    char dir[] = "NESW";
    bool vis[10000][10000] = {};
    vis[5000][5000] = true;
    for (char *p = path; *p; ++p) {
        int d = strchr(dir, *p) - dir;
        x += dx[d];
        y += dy[d];
        if (vis[x + 5000][y + 5000]) return true;
        vis[x + 5000][y + 5000] = true;
    }
    return false;
}