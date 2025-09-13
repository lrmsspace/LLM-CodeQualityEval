/*
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
import java.util.*;

class Solution {
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // 构建邻接表
        List<Integer>[] tree1 = buildGraph(n, edges1);
        List<Integer>[] tree2 = buildGraph(m, edges2);

        // 计算每棵树的直径
        int diameter1 = getDiameter(tree1, n);
        int diameter2 = getDiameter(tree2, m);

        // 获取每个节点出发的最大深度
        int[] maxDepths1 = getMaxDepths(tree1, n);
        int[] maxDepths2 = getMaxDepths(tree2, m);

        // 找出最大和次大的深度
        int max1 = 0, secondMax1 = 0;
        for (int depth : maxDepths1) {
            if (depth > max1) {
                secondMax1 = max1;
                max1 = depth;
            } else if (depth > secondMax1) {
                secondMax1 = depth;
            }
        }

        int max2 = 0, secondMax2 = 0;
        for (int depth : maxDepths2) {
            if (depth > max2) {
                secondMax2 = max2;
                max2 = depth;
            } else if (depth > secondMax2) {
                secondMax2 = depth;
            }
        }

        // 最优连接方式下最长的路径是 max(max1 + max2 + 1, max(diameter1, diameter2))
        int candidate = Math.max(Math.max(diameter1, diameter2), max1 + max2 + 1);

        return candidate;
    }

    private List<Integer>[] buildGraph(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        return graph;
    }

    private int bfs(int start, List<Integer>[] graph, int n, int[] dist) {
        Arrays.fill(dist, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        dist[start] = 0;
        int maxDist = 0;
        int farthestNode = start;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    queue.offer(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return farthestNode;
    }

    private int getDiameter(List<Integer>[] graph, int n) {
        int[] dist = new int[n];
        int farthest = bfs(0, graph, n, dist);
        bfs(farthest, graph, n, dist);
        int diameter = 0;
        for (int d : dist) {
            diameter = Math.max(diameter, d);
        }
        return diameter;
    }

    private int[] getMaxDepths(List<Integer>[] graph, int n) {
        int[] depths = new int[n];
        for (int i = 0; i < n; ++i) {
            int[] dist = new int[n];
            bfs(i, graph, n, dist);
            int maxDepth = 0;
            for (int d : dist) {
                maxDepth = Math.max(maxDepth, d);
            }
            depths[i] = maxDepth;
        }
        return depths;
    }
}