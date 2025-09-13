/**https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/ */
//There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
//You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
//Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
//The degree of a node is the number of edges connected to it.
// 
//Example 1:
//Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
//Output: true
//Explanation: The above diagram shows a valid way of adding an edge.
//Every node in the resulting graph is connected to an even number of edges.
//Example 2:
//Input: n = 4, edges = [[1,2],[3,4]]
//Output: true
//Explanation: The above diagram shows a valid way of adding two edges.
//Example 3:
//Input: n = 4, edges = [[1,2],[1,3],[1,4]]
//Output: false
//Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.
// 
//Constraints:
//	3 <= n <= 105
//	2 <= edges.length <= 105
//	edges[i].length == 2
//	1 <= ai, bi <= n
//	ai != bi
//	There are no repeated edges.
class Solution {
    public boolean isPossible(int n, List<List<Integer>> edges) {

        Set<Integer>[] graph = new Set[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new HashSet<>();
        }
        for (List<Integer> edge : edges) {
            graph[edge.get(0) - 1].add(edge.get(1) - 1);
            graph[edge.get(1) - 1].add(edge.get(0) - 1);
        }
        List<Integer> oddNodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (graph[i].size() % 2 != 0) {
                oddNodes.add(i);
            }
        }
        if (oddNodes.size() > 4 || oddNodes.size() % 2 != 0) {
            return false;
        }
        if (oddNodes.size() == 0) {
            return true;
        }
        if (oddNodes.size() == 2) {
            int a = oddNodes.get(0), b = oddNodes.get(1);
            if (!graph[a].contains(b)) {
                return true;
            }
            for (int i = 0; i < n; i++) {
                if (!graph[a].contains(i) && !graph[b].contains(i)) {
                    return true;
                }
            }
            return false;
        }
        int a = oddNodes.get(0), b = oddNodes.get(1), c = oddNodes.get(2), d = oddNodes.get(3);
        if (!graph[a].contains(b) && !graph[c].contains(d)) {
            return true;
        }
        if (!graph[a].contains(c) && !graph[b].contains(d)) {
            return true;
        }
        if (!graph[a].contains(d) && !graph[b].contains(c)) {
            return true;
        }
        return false;
    }
}