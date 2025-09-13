/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
 A special path is defined as a downward path from an ancestor node to a descendant node in which all node values are distinct, except for at most one value that may appear twice.
 Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
 Example 1:
 Input: edges = [[0,1,1],[1,2,3],[1,3,1],[2,4,6],[4,7,2],[3,5,2],[3,6,5],[6,8,3]], nums = [1,1,0,3,1,2,1,1,0]
 Output: [9,3]
 Explanation:
 In the image below, nodes are colored by their corresponding values in nums.
 The longest special paths are 1 -> 2 -> 4 and 1 -> 3 -> 6 -> 8, both having a length of 9. The minimum number of nodes across all longest special paths is 3.
 Example 2:
 Input: edges = [[1,0,3],[0,2,4],[0,3,5]], nums = [1,1,0,2]
 Output: [5,2]
 Explanation:
 The longest path is 0 -> 3 consisting of 2 nodes with a length of 5.
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
        int n = nums.length;
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            graph.get(u).add(new int[]{v, length});
            graph.get(v).add(new int[]{u, length});
        }

        int[] result = new int[2];
        boolean[] visited = new boolean[n];
        dfs(0, -1, 0, 0, visited, graph, nums, result);
        return result;
    }

    private void dfs(int node, int parent, int length, int count, boolean[] visited, List<List<int[]>> graph, int[] nums, int[] result) {
        visited[node] = true;
        if (length > result[0]) {
            result[0] = length;
            result[1] = count;
        } else if (length == result[0]) {
            result[1] = Math.min(result[1], count);
        }

        for (int[] neighbor : graph.get(node)) {
            int next = neighbor[0], edgeLength = neighbor[1];
            if (!visited[next]) {
                dfs(next, node, length + edgeLength, count + 1, visited, graph, nums, result);
            }
        }
        visited[node] = false;
    }
}