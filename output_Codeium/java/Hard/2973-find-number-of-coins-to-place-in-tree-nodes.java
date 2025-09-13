/*
 You are given an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 You are also given a 0-indexed integer array cost of length n, where cost[i] is the cost assigned to the ith node.
 You need to place some coins on every node of the tree. The number of coins to be placed at node i can be calculated as:
 If size of the subtree of node i is less than 3, place 1 coin.
 Otherwise, place an amount of coins equal to the maximum product of cost values assigned to 3 distinct nodes in the subtree of node i. If this product is negative, place 0 coins.
 Return an array coin of size n such that coin[i] is the number of coins placed at node i.
 Example 1:
 Input: edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
 Output: [120,1,1,1,1,1]
 Explanation: For node 0 place 6 * 5 * 4 = 120 coins. All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
 Example 2:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost = [1,4,2,3,5,7,8,-4,2]
 Output: [280,140,32,1,1,1,1,1,1]
 Explanation: The coins placed on each node are:
 - Place 8 * 7 * 5 = 280 coins on node 0.
 - Place 7 * 5 * 4 = 140 coins on node 1.
 - Place 8 * 2 * 2 = 32 coins on node 2.
 - All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
 Example 3:
 Input: edges = [[0,1],[0,2]], cost = [1,2,-2]
 Output: [0,1,1]
 Explanation: Node 1 and 2 are leaves with subtree of size 1, place 1 coin on each of them. For node 0 the only possible product of cost is 2 * 1 * -2 = -4. Hence place 0 coins on node 0.
 Constraints:
 2 <= n <= 2 * 104
 edges.length == n - 1
 edges[i].length == 2
 0 <= ai, bi < n
 cost.length == n
 1 <= |cost[i]| <= 104
 The input is generated such that edges represents a valid tree.
*/

class Solution {
    public long[] placedCoins(int[][] edges, int[] cost) {
        int n = cost.length;
        List<Integer>[] tree = new List[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        long[] dp = new long[n];
        Arrays.fill(dp, -1);
        long[] res = new long[n];
        dfs(tree, cost, dp, res, 0, -1);
        return res;

    }

    private void dfs(List<Integer>[] tree, int[] cost, long[] dp, long[] res, int node, int parent) {
        if (dp[node] != -1) {
            res[node] = dp[node];
            return;
        }
        List<Integer> children = new ArrayList<>();
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(tree, cost, dp, res, child, node);
                children.add(child);
            }
        }
        if (children.size() < 3) {
            dp[node] = 1;
        } else {
            long max = 0;
            for (int i = 0; i < children.size(); i++) {
                for (int j = i + 1; j < children.size(); j++) {
                    for (int k = j + 1; k < children.size(); k++) {
                        max = Math.max(max, (long) cost[children.get(i)] * cost[children.get(j)] * cost[children.get(k)]);
                    }
                }
            }
            dp[node] = max;
        }
        res[node] = dp[node];
        
    }
}