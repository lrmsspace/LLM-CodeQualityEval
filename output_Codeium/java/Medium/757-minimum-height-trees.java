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
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }
        
        int[] degree = new int[n];
        for (int[] edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.add(i);
            }
        }
        
        while (n > 2) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int node = queue.poll();
                for (int[] edge : edges) {
                    if (edge[0] == node) {
                        degree[edge[1]]--;
                        if (degree[edge[1]] == 1) {
                            queue.add(edge[1]);
                        }
                    } else if (edge[1] == node) {
                        degree[edge[0]]--;
                        if (degree[edge[0]] == 1) {
                            queue.add(edge[0]);
                        }
                    }
                }
            }
            n -= size;
        }
        
        while (!queue.isEmpty()) {
            res.add(queue.poll());
        }
        
        return res;
    }
}