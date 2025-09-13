/**https://leetcode.com/problems/minimize-the-total-price-of-the-trips/ */
//There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.
//The price sum of a given path is the sum of the prices of all nodes lying on that path.
//Additionally, you are given a 2D integer array trips, where trips[i] = [starti, endi] indicates that you start the ith trip from the node starti and travel to the node endi by any path you like.
//Before performing your first trip, you can choose some non-adjacent nodes and halve the prices.
//Return the minimum total price sum to perform all the given trips.
// 
//Example 1:
//Input: n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
//Output: 23
//Explanation: The diagram above denotes the tree after rooting it at node 2. The first part shows the initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their price half.
//For the 1st trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
//For the 2nd trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
//For the 3rd trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
//The total price sum of all trips is 6 + 7 + 10 = 23.
//It can be proven, that 23 is the minimum answer that we can achieve.
//Example 2:
//Input: n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
//Output: 1
//Explanation: The diagram above denotes the tree after rooting it at node 0. The first part shows the initial tree and the second part shows the tree after choosing node 0, and making its price half.
//For the 1st trip, we choose path [0]. The price sum of that path is 1.
//The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can achieve.
// 
//Constraints:
//	1 <= n <= 50
//	edges.length == n - 1
//	0 <= ai, bi <= n - 1
//	edges represents a valid tree.
//	price.length == n
//	price[i] is an even integer.
//	1 <= price[i] <= 1000
//	1 <= trips.length <= 100
//	0 <= starti, endi <= n - 1
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> p(n);
        function<void(int, int)> dfs = [&](int u, int fa) {
            p[u] = price[u];
            for (int v : g[u]) {
                if (v == fa) continue;
                dfs(v, u);
                p[u] += p[v];
            }
        };
        dfs(0, -1);
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        function<int(int, int, int)> f = [&](int u, int fa, int k) {
            if (dp[u][k] != INT_MAX) return dp[u][k];
            if (k == 0) return dp[u][k] = p[u];
            if (k == 1) return dp[u][k] = p[u] / 2;
            int res = p[u];
            for (int v : g[u]) {
                if (v == fa) continue;
                int sum = 0;
                for (int i = 0; i <= k - 2; ++i) {
                    sum = max(sum, f(v, u, i));
                }
                res = min(res, sum + f(v, u, k - 1));
            }
            return dp[u][k] = res;
        };
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f(0, -1, i));
        }
        int res = 0;
        for (auto& t : trips) {
            res += f(t[0], -1, t[1]);
        }
        return res;        
    }
};