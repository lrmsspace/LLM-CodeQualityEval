/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
// 
//Example 1:
//Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
//Output: 3
//Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
//Example 2:
//Input: colors = "a", edges = [[0,0]]
//Output: -1
//Explanation: There is a cycle from 0 to 0.
// 
//Constraints:
//	n == colors.length
//	m == edges.length
//	1 <= n <= 105
//	0 <= m <= 105
//	colors consists of lowercase English letters.
//	0 <= aj, bj < n
import java.util.ArrayList;
import java.util.List;
class Solution {

    public int largestPathValue(String colors, int[][] edges) {


        int n = colors.length(); // number of nodes
        int m = edges.length; // number of edges

        int[][] count = new int[n][26]; // count[i][j] is the number of nodes with color j in the path from node 0 to node i

        int[] inDegree = new int[n]; // inDegree[i] is the number of nodes that have an edge pointing to node i

        List<List<Integer>> adj = new ArrayList<>(); // adj[i] is the list of nodes that have an edge pointing to node i

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            inDegree[edge[1]]++;
        }
        int[] queue = new int[n];

        int front = 0;
        int rear = 0;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue[rear++] = i;
            }
        }
        int ans = 0;

        int cnt = 0;

        while (front < rear) {
            int node = queue[front++];
            ans = Math.max(ans, ++count[node][colors.charAt(node) - 'a']);
            cnt++;
            for (int neighbor : adj.get(node)) {
                for (int i = 0; i < 26; i++) {
                    count[neighbor][i] = Math.max(count[neighbor][i], count[node][i]);
                }
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue[rear++] = neighbor;
                }
            }
        }

        return cnt < n ? -1 : ans;

    }

}