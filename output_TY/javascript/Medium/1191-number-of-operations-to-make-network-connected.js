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
    let graph = new Map();
    let visited = new Set();
    let count = 0;
    let edges = 0;
    for(let i = 0; i < connections.length; i++){
        if(!graph.has(connections[i][0])){
            graph.set(connections[i][0], []);
        }
        if(!graph.has(connections[i][1])){
            graph.set(connections[i][1], []);
        }
        graph.get(connections[i][0]).push(connections[i][1]);
        graph.get(connections[i][1]).push(connections[i][0]);
        edges++;
    }
    for(let i = 0; i < n; i++){
        if(!visited.has(i)){
            count++;
            dfs(i);
        }
    }   
    if(count > 1 || edges < count - 1){
        return -1;
    }
    return count - 1;
};