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
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int* parent = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    int* dist = (int*)malloc(sizeof(int) * n);
    memset(dist, 0, sizeof(int) * n);
    int* visited = (int*)malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int d = abs(points[minIndex][0] - points[j][0]) + abs(points[minIndex][1] - points[j][1]);
                if (d < dist[j]) {
                    dist[j] = d;
                    parent[j] = minIndex;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        res += abs(points[i][0] - points[find(i)][0]) + abs(points[i][1] - points[find(i)][1]);
    }
    return res;
}