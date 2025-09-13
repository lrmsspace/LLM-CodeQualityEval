/*
 There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
 You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
 Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
 Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
 Output: [8,7,7,8,8]
 Explanation:
 For i = 0, connect node 0 from the first tree to node 0 from the second tree.
 For i = 1, connect node 1 from the first tree to node 4 from the second tree.
 For i = 2, connect node 2 from the first tree to node 7 from the second tree.
 For i = 3, connect node 3 from the first tree to node 0 from the second tree.
 For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
 Output: [3,6,6,6,6]
 Explanation:
 For every i, connect node i of the first tree with any node of the second tree.
 Constraints:
 2 <= n, m <= 105
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
*/

class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1;
        int m = edges2.length + 1;
        int[] res = new int[n];
        int[] indegree = new int[m];
        
        for (int[] edge : edges1) {
            indegree[edge[1]]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
            res[i] = 0;
            res[0] += 1;
            res[n - 1] += 1;
            res[edges1[0][0]] -= 1;
            res[edges1[0][1]] -= 1;
            res[edges1[edges1.length - 1][0]] += 1;
            res[edges1[edges1.length - 1][1]] += 1;

            for (int[] edge : edges2) {
                if (edge[0] == i) {
                    res[edge[1]]++;
                }
            }
        }
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int[] edge : edges1) {
                if (edge[0] == u) {
                    res[edge[1]]++;
                    indegree[edge[1]]--;
                    if (indegree[edge[1]] == 0) {
                        queue.offer(edge[1]);
                    }
                }
            }
        }
        return res;
        
    }
}