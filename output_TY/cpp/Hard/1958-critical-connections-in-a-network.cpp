/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto& edge : connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> ans;
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        int time = 0;
        dfs(graph, 0, -1, low, disc, time, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, int node, int parent, vector<int>& low, vector<int>&disc, int& time, vector<vector<int>>& ans){
        low[node] = disc[node] = time++;
        for(auto& next : graph[node]){
            if(next == parent) continue;
            if(disc[next] == -1){
                dfs(graph, next, node, low, disc, time, ans);
                low[node] = min(low[node], low[next]);
                if(low[next] > disc[node]){
                    ans.push_back({node, next});
                }
            }
            else{
                low[node] = min(low[node], disc[next]);
            }
        }
        return;
    }
};