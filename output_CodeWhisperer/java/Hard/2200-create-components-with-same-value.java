/**https://leetcode.com/problems/create-components-with-same-value/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1.
//You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//You are allowed to delete some edges, splitting the tree into multiple connected components. Let the value of a component be the sum of all nums[i] for which node i is in the component.
//Return the maximum number of edges you can delete, such that every connected component in the tree has the same value.
// 
//Example 1:
//Input: nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
//Output: 2 
//Explanation: The above figure shows how we can delete the edges [0,1] and [3,4]. The created components are nodes [0], [1,2,3] and [4]. The sum of the values in each component equals 6. It can be proven that no better deletion exists, so the answer is 2.
//Example 2:
//Input: nums = [2], edges = []
//Output: 0
//Explanation: There are no edges to be deleted.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	nums.length == n
//	1 <= nums[i] <= 50
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= edges[i][0], edges[i][1] <= n - 1
//	edges represents a valid tree.
class Solution {
    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        int[] parent = new int[n];
        Arrays.fill(parent, -1);
        parent[0] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph[node]) {
                if (parent[neighbor] == -1) {
                    parent[neighbor] = node;
                    queue.offer(neighbor);
                }
            }
        }
        int[] xor = new int[n];
        for (int i = 0; i < n; i++) {
            xor[i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            xor[parent[edges[i][1]]] ^= xor[edges[i][1]];
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = parent[edges[i][0]], b = parent[edges[i][1]];
            if (a == b) {
                a = parent[edges[i][1]];
                b = parent[edges[i][0]];
            }
            int[] x = {xor[edges[i][0]], xor[edges[i][1]], xor[edges[i][0]] ^ xor[edges[i][1]]};
            Arrays.sort(x);
            res = Math.max(res, x[2] == x[1] ? x[0] : x[2]);
        }
        return res;      
    }
}