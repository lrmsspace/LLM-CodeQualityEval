/**https://leetcode.com/problems/min-cost-to-connect-all-points/ */
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
// 
//Example 1:
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation: 
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
// 
//Constraints:
//	1 <= points.length <= 1000
//	-106 <= xi, yi <= 106
//	All pairs (xi, yi) are distinct.

int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int edges[n * (n - 1) / 2][3];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[idx][0] = i;
            edges[idx][1] = j;
            edges[idx][2] = dis;
            idx++;
        }
    }
    sort(edges, edges + idx, [](int a[], int b[]) {
        return a[2] < b[2];
    });
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int res = 0;
    for (int i = 0; i < idx; i++) {
        int fa = find(parent, edges[i][0]);
        int fb = find(parent, edges[i][1]);
        if (fa != fb) {
            res += edges[i][2];
            parent[fa] = fb;
        }
    }
    return res;
}   