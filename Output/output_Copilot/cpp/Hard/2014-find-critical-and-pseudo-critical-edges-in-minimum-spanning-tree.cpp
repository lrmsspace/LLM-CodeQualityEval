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
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        int minCost = 0;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto join = [&](int x, int y) {
            parent[find(x)] = find(y);
        };
        function<int(int)> mst = [&](int skip) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            int res = 0, cnt = 0;
            if (skip != -1) {
                auto& e = edges[skip];
                join(e[0], e[1]);
                res += e[2];
                cnt++;
            }
            for (int i = 0; i < m; i++) {
                if (i == skip) {
                    continue;
                }
                auto& e = edges[i];
                if (find(e[0]) != find(e[1])) {
                    join(e[0], e[1]);
                    res += e[2];
                    cnt++;
                }
            }
            return cnt == n - 1 ? res : INT_MAX;
        };
        minCost = mst(-1);
        vector<int> critical, pseudoCritical;
        for (int i = 0; i < m; i++) {
            if (mst(i) > minCost) {
                critical.push_back(edges[i][3]);
            } else if (mst(-1) == mst(i)) {
                pseudoCritical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo
Critical};  
    }
};