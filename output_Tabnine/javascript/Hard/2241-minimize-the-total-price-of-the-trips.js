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
/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} price
 * @param {number[][]} trips
 * @return {number}
 */
var minimumTotalPrice = function(n, edges, price, trips) {
    // Build adjacency list
    const adjList = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        adjList[a].push(b);
        adjList[b].push(a);
    }
    
    // Initialize visited array
    const visited = Array.from({ length: n }, () => false);
    
    // Initialize result
    let result = 0;
    
    // DFS to calculate total price for each trip
    function dfs(node, parent) {
        let totalPrice = price[node];
        
        for (const neighbor of adjList[node]) {
            if (neighbor!== parent &&!visited[neighbor]) {
                visited[neighbor] = true;
                totalPrice += dfs(neighbor, node);
            }
        }
        
        return totalPrice;
    }
    
    // DFS to calculate minimum total price
    function dfsForTrips(trip) {
        const [start, end] = trip;
        
        if (visited[start] || visited[end]) {
            return;
        }
        
        visited[start] = visited[end] = true;
        
        const totalPrice1 = dfs(start, -1);
        const totalPrice2 = dfs(end, -1);
        
        result += Math.min(totalPrice1, totalPrice2);
        
        dfsForTrips([start, end]);
        dfsForTrips([end, start]);
    }
    
    // DFS to calculate minimum total price for all trips
    for (const trip of trips) {
        dfsForTrips(trip);
    }
    
    return result;
    
};