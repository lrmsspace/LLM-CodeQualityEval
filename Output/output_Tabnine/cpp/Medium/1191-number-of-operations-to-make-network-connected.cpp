/**https://leetcode.com/problems/number-of-operations-to-make-network-connected/ */
//There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
//You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
//Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[0,2],[1,2]]
//Output: 1
//Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
//Example 2:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
//Output: 2
//Example 3:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
//Output: -1
//Explanation: There are not enough cables.
// 
//Constraints:
//	1 <= n <= 105
//	1 <= connections.length <= min(n * (n - 1) / 2, 105)
//	connections[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	There are no repeated connections.
//	No two computers are connected by more than one cable.
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return x == parent[x]? x : parent[x] = find(parent[x]);
        };
        
        function<bool(int, int)> merge = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x!= y) parent[x] = y;
            return x!= y;
        };
        
        for (const auto& connection : connections)
            merge(connection[0], connection[1]);
        
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (find(i) == i) ++count;
            
        return count - 1;  // Return the number of disjoint sets - 1, which is the minimum number of cables needed.
        
    }
};