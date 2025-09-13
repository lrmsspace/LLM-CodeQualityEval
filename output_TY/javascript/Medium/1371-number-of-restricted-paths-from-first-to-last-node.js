/**https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/ */
//There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
//A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
//The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
//Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
//Output: 3
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
//1) 1 --> 2 --> 5
//2) 1 --> 2 --> 3 --> 5
//3) 1 --> 3 --> 5
//Example 2:
//Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
//Output: 1
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	n - 1 <= edges.length <= 4 * 104
//	edges[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	1 <= weighti <= 105
//	There is at most one edge between any two nodes.
//	There is at least one path between any two nodes.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countRestrictedPaths = function(n, edges) {
    let adj = new Array(n+1).fill(0).map(()=>new Array());
    for(let i=0;i<edges.length;i++){
        adj[edges[i][0]].push([edges[i][1],edges[i][2]]);
        adj[edges[i][1]].push([edges[i][0],edges[i][2]]);
    }
    let dist = new Array(n+1).fill(Infinity);
    let q = [];
    q.push([n,0]);
    dist[n] = 0;
    while(q.length){
        let [node,dis] = q.shift();
        for(let i=0;i<adj[node].length;i++){
            let [nextNode,nextDis] = adj[node][i];
            if(dis+nextDis<dist[nextNode]){
                dist[nextNode] = dis+nextDis;
                q.push([nextNode,dis+nextDis]);
            }
        }
    }
    let dp = new Array(n+1).fill(0);
    dp[n] = 1;
    for(let i=n-1;i>=1;i--){
        for(let j=0;j<adj[i].length;j++){
            let [nextNode,nextDis] = adj[i][j];
            if(dist[nextNode]>dist[i]){
                dp[i] = (dp[i] + dp[nextNode])%1000000007;
            }
        }
    }
    return dp[1];
};