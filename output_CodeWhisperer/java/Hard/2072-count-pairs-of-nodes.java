/**https://leetcode.com/problems/count-pairs-of-nodes/ */
//You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
//Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
//The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
//	a < b
//	incident(a, b) > queries[j]
//Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
//Note that there can be multiple edges between the same two nodes.
// 
//Example 1:
//Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
//Output: [6,5]
//Explanation: The calculations for incident(a, b) are shown in the table above.
//The answers for each of the queries are as follows:
//- answers[0] = 6. All the pairs have an incident(a, b) value greater than 2.
//- answers[1] = 5. All the pairs except (3, 4) have an incident(a, b) value greater than 3.
//Example 2:
//Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
//Output: [10,10,9,8,6]
// 
//Constraints:
//	2 <= n <= 2 * 104
//	1 <= edges.length <= 105
//	1 <= ui, vi <= n
//	ui != vi
//	1 <= queries.length <= 20
//	0 <= queries[j] < edges.length


class Solution {
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        int[] ans = new int[queries.length];
        int[] cnt = new int[n + 1];
        HashMap<Integer, Integer> shared = new HashMap<>();
        for (int[] edge : edges) {
            int u = Math.min(edge[0], edge[1]), v = Math.max(edge[0], edge[1]);
            cnt[u]++;
            cnt[v]++;
            shared.put(u * n + v, shared.getOrDefault(u * n + v, 0) + 1);
        }
        int[] arr = new int[n];
        for (int i = 1; i <= n; i++) {
            arr[i - 1] = cnt[i];
        }
        Arrays.sort(arr);
        for (int i = 0; i < queries.length; i++) {
            int l = 1, r = n;
            while (l < r) {
                if (arr[l] + arr[r] > queries[i]) {
                    ans[i] += r - l;
                    r--;
                } else {
                    l++;
                }
            }
            for (int key : shared.keySet()) {
                int u = key / n, v = key % n;
                int sum = cnt[u] + cnt[v];
                if (sum > queries[i] && sum - shared.get(key) <= queries[i]) {
                    ans[i]--;
                }
            }
        }
        return ans;
        
    }
}