/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
// 
//Example 1:
//Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
//Output: 3
//Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.
//Example 2:
//Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
//Output: 0
//Explanation: There are exactly three trios:
//1) [1,4,3] with degree 0.
//2) [2,5,6] with degree 2.
//3) [5,6,7] with degree 2.
// 
//Constraints:
//	2 <= n <= 400
//	edges[i].length == 2
//	1 <= edges.length <= n * (n-1) / 2
//	1 <= ui, vi <= n
//	ui != vi
//	There are no repeated edges.
int minTrioDegree(int n, int** edges, int edgesSize, int* edgesColSize) {
    int deg = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int d = 0;
        for (int j = 0; j < edgesSize; ++j) {
            if (edges[j][0] == i || edges[j][1] == i) ++d;
        }
        for (int j = 0; j < edgesSize; ++j) {
            if ((edges[j][0] == i && edges[j][1] > i) || (edges[j][1] == i && edges[j][0] > i)) {
                int k = edges[j][1] > i ? edges[j][1] : edges[j][0];
                bool ok = false;
                for (int l = 0; l < edgesSize; ++l) {
                    if (l != j && (edges[l][0] == k || edges[l][1] == k) && (edges[l][0] == i || edges[l][1] == i)) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) continue;
                deg = std::min(deg, d);
            }
        }
    }
    return deg == INT_MAX ? -1 : deg;
}
