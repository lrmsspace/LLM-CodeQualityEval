/*
import java.util.List;
import java.util.ArrayList;
 There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 You must connect one node from the first tree with another node from the second tree with an edge.
 Return the minimum possible diameter of the resulting tree.
 The diameter of a tree is the length of the longest path between any two nodes in the tree.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
 Output: 3
 Explanation:
 We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
 Output: 5
 Explanation:
 We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
 Constraints:
 1 <= n, m <= 105
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
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // Create adjacency lists for both trees
        List<List<Integer>> graph1 = new ArrayList<>();
        List<List<Integer>> graph2 = new ArrayList<>();
        for (int i = 0; i < n + m; i++) {
            graph1.add(new ArrayList<>());
            graph2.add(new ArrayList<>());
        }

        // Build adjacency lists for the first tree
        for (int[] edge : edges1) {
            graph1.get(edge[0]).add(edge[1]);
            graph1.get(edge[1]).add(edge[0]);
        }

        // Build adjacency lists for the second tree
        for (int[] edge : edges2) {
            graph2.get(edge[0] + n).add(edge[1] + n);
            graph2.get(edge[1] + n).add(edge[0] + n);
        }
        int maxDiameter = 0;
        int[] diameter1 = new int[n + m];

        // Calculate the diameter of the first tree
        for (int i = 0; i < n; i++) {
            diameter1[i] = dfs(i, -1, graph1);
            maxDiameter = Math.max(maxDiameter, diameter1[i]);
        }

        // Calculate the diameter of the second tree
        int[] diameter2 = new int[n + m];


        for (int i = n; i < n + m; i++) {
            diameter2[i] = dfs(i, -1, graph2);
            maxDiameter = Math.max(maxDiameter, diameter2[i]);
        }


        // Find the best connection between the two trees
        for (int i = 0; i < n; i++) {
            for (int j = n; j < n + m; j++) {
                maxDiameter = Math.max(maxDiameter, diameter1[i] + diameter2[j]);
            }
        }
        return maxDiameter;
                
    }
}