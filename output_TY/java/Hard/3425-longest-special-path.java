/*
 You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1, represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
 A special path is defined as a downward path from an ancestor node to a descendant node such that all the values of the nodes in that path are unique.
 Note that a path may start and end at the same node.
 Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
 Example 1:
 Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
 Output: [6,2]
 Explanation:
 In the image below, nodes are colored by their corresponding values in nums
 The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a length of 6. The minimum number of nodes across all longest special paths is 2.
 Example 2:
 Input: edges = [[1,0,8]], nums = [2,2]
 Output: [0,1]
 Explanation:
 The longest special paths are 0 and 1, both having a length of 0. The minimum number of nodes across all longest special paths is 1.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= lengthi <= 103
 nums.length == n
 0 <= nums[i] <= 5 * 104
 The input is generated such that edges represents a valid tree.
*/

class Solution {
    public int[] longestSpecialPath(int[][] edges, int[] nums) {
        
        int n = edges.length + 1;
        List<Integer>[] g = new List[n];    
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].add(v);
            g[v].add(u);
        }
        int[] ans = new int[n];
        int[] sum = new int[n];
        int[] cnt = new int[n];
        boolean[] vis = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        vis[0] = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.offer(v);
                    sum[v] = sum[u] + cnt[u];
                    ans[v] = Math.max( ans[u], ans[v]) + sum[u] - cnt[u] + cnt[u] * (cnt[u] - 1) / 2;
                }
            }
        }
        return ans;
    }
}