/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.
// 
//Example 1:
//Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
//Output: [[0,1],[2,3,4,5]]
//Explanation: The figure above describes the graph.
//The following figure shows all the possible MSTs:
//Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
//The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
//Example 2:
//Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
//Output: [[],[0,1,2,3]]
//Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
// 
//Constraints:
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= ai < bi < n
//	1 <= weighti <= 1000
//	All pairs (ai, bi) are distinct.
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2);
        vector<int> critical, pseudo;
  

        // sort edges by weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        // find mst weight using union find
        int mst_weight = 0;

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if (x != y) {
                parent[x] = y;
                mst_weight += edge[2];
            }
        }

        // check each edge
        for (int i = 0; i < edges.size(); i++) {
            // ignore this edge and find mst weight
            int ignore_weight = 0;
            vector<int> ignore_parent(n);
            for (int j = 0; j < n; j++) {
                ignore_parent[j] = j;
            }
            for (int j = 0; j < edges.size(); j++) {
                if (i != j) {
                    int x = find(ignore_parent, edges[j][0]);
                    int y = find(ignore_parent, edges[j][1]);
                    if (x != y) {
                        ignore_parent[x] = y;
                        ignore_weight += edges[j][2];
                    }
                }
            }
            // if the ignore_weight is greater than mst_weight, this edge is critical
            if (ignore_weight > mst_weight) {
                critical.push_back(i);
            } else {
                // else, we need to check if this edge is pseudo-critical
                // find mst weight without this edge
                int without_weight = 0;
                vector<int> without_parent(n);
                for (int j = 0; j < n; j++) {
                    without_parent[j] = j;
                }
                for (int j = 0; j < edges.size(); j++) {
                    if (i != j) {
                        int x = find(without_parent, edges[j][0]);
                        int y = find(without_parent, edges[j][1]);
                        if (x != y) {
                            without_parent[x] = y;
                            without_weight += edges[j][2];
                        }
                    }
                }
                // if the mst weight is the same as the weight without this edge, this edge is pseudo-critical
                if (without_weight == mst_weight) {
                    pseudo.push_back(i);
                }
            }
        }
        res[0] = critical;
        res[1] = pseudo;
        return res;
    }
};