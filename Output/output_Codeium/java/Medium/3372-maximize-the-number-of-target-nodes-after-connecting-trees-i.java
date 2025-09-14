/*
 There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
 You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
 Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
 Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
 Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
 Output: [9,7,9,8,8]
 Explanation:
 For i = 0, connect node 0 from the first tree to node 0 from the second tree.
 For i = 1, connect node 1 from the first tree to node 0 from the second tree.
 For i = 2, connect node 2 from the first tree to node 4 from the second tree.
 For i = 3, connect node 3 from the first tree to node 4 from the second tree.
 For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
 Output: [6,3,3,3,3]
 Explanation:
 For every i, connect node i of the first tree with any node of the second tree.
 Constraints:
 2 <= n, m <= 1000
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
 0 <= k <= 1000
*/

class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.length + 1;
        int m = edges2.length + 1;
        
        List<List<Integer>> tree1 = buildTree(edges1, n);
        List<List<Integer>> tree2 = buildTree(edges2, m);

        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            boolean[] visited1 = new boolean[n];
            boolean[] visited2 = new boolean[m];
            dfs(tree1, i, 0, k, visited1);
            
            for (int j = 0; j < m; j++) {
                Arrays.fill(visited2, false);
                dfs(tree2, j, 0, k, visited2);
                answer[i] = Math.max(answer[i], countTrue(visited1) + countTrue(visited2));
            }
        }
        
        return answer;
    }

    private List<List<Integer>> buildTree(int[][] edges, int size) {
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            tree.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }
        return tree;
    }

    private void dfs(List<List<Integer>> tree, int node, int depth, int k, boolean[] visited) {
        if (depth > k || visited[node]) return;
        visited[node] = true;
        for (int neighbor : tree.get(node)) {
            dfs(tree, neighbor, depth + 1, k, visited);
        }
    }

    private int countTrue(boolean[] array) {
        int count = 0;
        for (boolean b : array) {
            if (b) count++;
        }
        return count;
    }
}

