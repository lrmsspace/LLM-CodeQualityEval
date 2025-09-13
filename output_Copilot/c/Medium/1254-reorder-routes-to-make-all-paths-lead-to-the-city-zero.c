/**https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/ */
//There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
//Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
//This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
//Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
//It's guaranteed that each city can reach city 0 after reorder.
// 
//Example 1:
//Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
//Output: 3
//Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
//Example 2:
//Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
//Output: 2
//Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
//Example 3:
//Input: n = 3, connections = [[1,0],[2,0]]
//Output: 0
// 
//Constraints:
//	2 <= n <= 5 * 104
//	connections.length == n - 1
//	connections[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int *in = (int *)malloc(sizeof(int) * n);
    int *out = (int *)malloc(sizeof(int) * n);
    int *visited = (int *)malloc(sizeof(int) * n);
    int i = 0;
    int ret = 0;
    for (i = 0; i < n; i++) {
        in[i] = 0;
        out[i] = 0;
        visited[i] = 0;
    }
    for (i = 0; i < connectionsSize; i++) {
        out[connections[i][0]]++;
        in[connections[i][1]]++;
    }
    visited[0] = 1;
    for (i = 0; i < n; i++) {
        if (visited[i] == 1) {
            for (int j = 0; j < connectionsSize; j++) {
                if (connections[j][0] == i && visited[connections[j][1]] == 0) {
                    visited[connections[j][1]] = 1;
                    ret++;
                } else if (connections[j][1] == i && visited[connections[j][0]] == 0) {
                    visited[connections[j][0]] = 1;
                }
            }
        }
    }
    return ret;    
}