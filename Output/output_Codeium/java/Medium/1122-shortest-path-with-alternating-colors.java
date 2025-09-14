/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] answer = new int[n];
        Arrays.fill(answer, -1);
        answer[0] = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0, -1});
        while (!queue.isEmpty()) {
            int[] node = queue.poll();
            int curNode = node[0], curStep = node[1], preColor = node[2];
            if (curStep > answer[curNode]) {
                continue;
            }
            answer[curNode] = curStep;
            for (int[] edge : preColor == 0 ? blueEdges : redEdges) {
                if (edge[0] == curNode && edge[1] != -1) {
                    queue.add(new int[]{edge[1], curStep + 1, preColor == 0 ? 1 : 0});
                    edge[1] = -1;
                }
            }
        }
        return answer;
    }
}