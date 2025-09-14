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
/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var makeConnected = function(n, connections) {
    const parent = Array(n).fill(-1);
    
    function find(x) {
        if (parent[x] === -1) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    function union(x, y) {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX === rootY) return;
        parent[rootX] = rootY;
    }
    
    connections.forEach(([x, y]) => union(x, y));
    
    let count = connections.length;
    for (let i = 0; i < n; i++) {
        if (parent[i] === -1) count--;
    }
    
    return count < n - 1? -1 : connections.length - count;
    
};