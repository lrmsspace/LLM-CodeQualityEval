/**https://leetcode.com/problems/valid-square/ */
//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//	p1.length == p2.length == p3.length == p4.length == 2
//	-104 <= xi, yi <= 104
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    int dx[4] = {p2[0] - p1[0], p3[0] - p1[0], p4[0] - p1[0], p2[0] - p3[0]};
    int dy[4] = {p2[1] - p1[1], p3[1] - p1[1], p4[1] - p1[1], p2[1] - p3[1]};
    int d[4] = {0};
    for (int i = 0; i < 4; i++) {
        d[i] = dx[i] * dx[i] + dy[i] * dy[i];
    }
    int c = 0, a = 0;
    for (int i = 0; i < 4; i++) {
        if (d[i] == 0) continue;
        if (d[i] == a) c++;
        else a = d[i], c = 1;
    }
    return c == 4;
}