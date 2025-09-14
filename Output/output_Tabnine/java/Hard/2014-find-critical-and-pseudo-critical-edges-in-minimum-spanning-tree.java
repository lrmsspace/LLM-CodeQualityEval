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
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        List<List<Integer>> res = new ArrayList<>();
        List<Edge> edgeList = new ArrayList<>();
        for (int i = 0; i < edges.length; i++) {
            edgeList.add(new Edge(edges[i][0], edges[i][1], edges[i][2], i));
        }
        edgeList.sort(Comparator.comparingInt(e -> e.weight));
        
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int[] rank = new int[n];
        
        for (Edge edge : edgeList) {
            int u = find(parent, edge.u);
            int v = find(parent, edge.v);
            if (u!= v) {
                union(parent, rank, u, v);
                if (edge.weight > 1) {
                    res.get(0).add(edge.index);
                }
            }
        }
        
        int[] mstWeight = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            mstWeight[i] = edgeList.get(i).weight;
        }
        
        for (int i = 0; i < edgeList.size(); i++) {
            int u = find(parent, edgeList.get(i).u);
            int v = find(parent, edgeList.get(i).v);
            if (u!= v) {
                union(parent, rank, u, v);
                int newMstWeight = 0;
                for (int j = 0; j < n - 1; j++) {
                    newMstWeight += edgeList.get(j).weight;
                }
                if (newMstWeight < mstWeight[i]) {
                    res.get(1).add(edgeList.get(i).index);
                } else {
                    res.get(0).add(edgeList.get(i).index);
                }
            }
        }
        
        return res;
    }
}