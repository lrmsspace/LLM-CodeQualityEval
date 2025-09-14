/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
// 
//Example 1:
//Input: n = 4, edges = [[1,0],[1,2],[1,3]]
//Output: [1]
//Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
//Example 2:
//Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//Output: [3,4]
// 
//Constraints:
//	1 <= n <= 2 * 104
//	edges.length == n - 1
//	0 <= ai, bi < n
//	ai != bi
//	All the pairs (ai, bi) are distinct.
//	The given input is guaranteed to be a tree and there will be no repeated edges.
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) return List.of(0); // Special case: single node tree

        // Create an adjacency list for the graph
        List<List<Integer>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        // Initialize leaves
        Queue<Integer> leaves = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (graph.get(i).size() == 1) {
                leaves.offer(i);
            }
        }

        // Trim the leaves until we reach the centroids
        while (n > 2) {
            int size = leaves.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int leaf = leaves.poll();
                for (int neighbor : graph.get(leaf)) {
                    graph.get(neighbor).remove(Integer.valueOf(leaf)); // Remove the leaf from its neighbor's list
                    if (graph.get(neighbor).size() == 1) { // If it becomes a leaf, add it to the queue
                        leaves.offer(neighbor);
                    }
                }
            }
        }

        return new ArrayList<>(leaves); // Remaining nodes are the centroids        
    }
}