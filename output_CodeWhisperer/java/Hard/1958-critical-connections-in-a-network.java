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
import java.util.ArrayList;
class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) 
    {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            graph.add(new ArrayList<>());
        }
        for (List<Integer> connection : connections)
        {
            graph.get(connection.get(0)).add(connection.get(1));
            graph.get(connection.get(1)).add(connection.get(0));
        }
        int[] disc = new int[n];
        int[] low = new int[n];
        List<List<Integer>> res = new ArrayList<>();
        int time = 1;
        dfs(graph, disc, low, res, 0, -1, time);
        return res;
    
    }
}