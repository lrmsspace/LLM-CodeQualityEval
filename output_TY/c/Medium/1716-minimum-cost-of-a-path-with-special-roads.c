/**https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/ */
//You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).
//The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.
//There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.
//Return the minimum cost required to go from (startX, startY) to (targetX, targetY).
// 
//Example 1:
//Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
//Output: 5
//Explanation: The optimal path from (1,1) to (4,5) is the following:
//- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
//- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
//- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
//- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
//So the total cost is 1 + 2 + 1 + 1 = 5.
//It can be shown that we cannot achieve a smaller total cost than 5.
//Example 2:
//Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
//Output: 7
//Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
// 
//Constraints:
//	start.length == target.length == 2
//	1 <= startX <= targetX <= 105
//	1 <= startY <= targetY <= 105
//	1 <= specialRoads.length <= 200
//	specialRoads[i].length == 5
//	startX <= x1i, x2i <= targetX
//	startY <= y1i, y2i <= targetY
//	1 <= costi <= 105
int minimumCost(int* start, int startSize, int* target, int targetSize, int** specialRoads, int specialRoadsSize, int* specialRoadsColSize){
    int n = specialRoadsSize;
    int m = 2 * n + 2;
    int* dist = (int*)malloc(sizeof(int) * m);
    int* prev = (int*)malloc(sizeof(int) * m);
    int* vis = (int*)malloc(sizeof(int) * m);
    int* cost = (int*)malloc(sizeof(int) * m);
    int* x =(int*)malloc(sizeof(int) * m);
    int* y = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        vis[i] = 0;
        cost[i] = 0;
        x[i] = 0;
        y[i] = 0;
    }
    x[0] = start[0];
    y[0] = start[1];
    dist[0] = 0;
    int startNode = 0;
    int endNode = 1;
    int startX = start[0];
    int startY = start[1];
    int targetX = target[0];
    int targetY = target[1];
    for (int i = 0; i < n; i++) {
        int x1 = specialRoads[i][0];
        int y1 = specialRoads[i][1];
        int x2 = specialRoads[i][2];
        int y2 = specialRoads[i][3];
        int costi = specialRoads[i][4];
        int node = i + 2;
        x[node] = x2;
    }
    for (int i = 0; i < n; i++) {
        int x1 = specialRoads[i][0];
        int y1 = specialRoads[i][1];
        int x2 = specialRoads[i][2];
        int y2 = specialRoads[i][3];
        int costi = specialRoads[i][4];
        int node = i + 2;
        int node1 = node + n;
    }
    while (1) {
        int min = INT_MAX;
        int u = -1;
        for (int i = 0; i < m; i++) {
            if (vis[i] == 0 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        vis[u]= 1;
    }
    return 0;
}