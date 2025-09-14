/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.
//Notice that the distance between the two cities is the number of edges in the path between them.
// 
//Example 1:
//Input: n = 4, edges = [[1,2],[2,3],[2,4]]
//Output: [3,4,0]
//Explanation:
//The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
//The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
//No subtree has two nodes where the max distance between them is 3.
//Example 2:
//Input: n = 2, edges = [[1,2]]
//Output: [1]
//Example 3:
//Input: n = 3, edges = [[1,2],[2,3]]
//Output: [2,1]
// 
//Constraints:
//	2 <= n <= 15
//	edges.length == n-1
//	edges[i].length == 2
//	1 <= ui, vi <= n
//	All pairs (ui, vi) are distinct.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 
    #define MAX_N 15

    int graph[MAX_N][MAX_N];
    bool visited[MAX_N];
    int maxDist, farthestNode;

    void dfs(int node, int dist, int n) {
        visited[node] = true;
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                dfs(i, dist + 1, n);
            }
        }
    }

    int calculateDiameter(int subset, int n) {
        memset(visited, 0, sizeof(visited));
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                startNode = i;
                break;
            }
        }
        if (startNode == -1) return 0;

        maxDist = 0;
        dfs(startNode, 0, n);

        memset(visited, 0, sizeof(visited));
        maxDist = 0;
        dfs(farthestNode, 0, n);

        for (int i = 0; i < n; i++) {
            if ((subset & (1 << i)) && !visited[i]) {
                return 0;
            }
        }

        return maxDist;
    }

    int* countSubgraphsForEachDiameter(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < edgesSize; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        int* result = (int*)calloc(n - 1, sizeof(int));
        for (int subset = 1; subset < (1 << n); subset++) {
            int diameter = calculateDiameter(subset, n);
            if (diameter > 0 && diameter < n) {
                result[diameter - 1]++;
            }
        }

        *returnSize = n - 1;
        return result;
    }

        