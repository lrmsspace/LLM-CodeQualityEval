/**https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/ */
//You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//Return the number of pairs of different nodes that are unreachable from each other.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[0,2],[1,2]]
//Output: 0
//Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
//Example 2:
//Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
//Output: 14
//Explanation: There are 14 pairs of nodes that are unreachable from each other:
//[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
//Therefore, we return 14.
// 
//Constraints:
//	1 <= n <= 105
//	0 <= edges.length <= 2 * 105
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	There are no repeated edges.    
long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize) {
    long long totalPairs = (long long)n * (n - 1) / 2;
    int* parent = (int*)malloc(n * sizeof(int));
    int* size = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < edgesSize; ++i) {
        int a = edges[i][0];
        int b = edges[i][1];
        while (a != parent[a]) a = parent[a];
        while (b != parent[b]) b = parent[b];
        if (a != b) {
            if (size[a] < size[b]) {
                parent[a] = b;
                size[b] += size[a];
            } else {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        while (i != parent[i]) i = parent[i];
    }

    int* componentSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        componentSize[parent[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if (componentSize[i] > 1) {
            totalPairs -= (long long)componentSize[i] * (componentSize[i] - 1) / 2;
        }
    }

    free(parent);
    free(size);
    free(componentSize);

    return totalPairs;
}

