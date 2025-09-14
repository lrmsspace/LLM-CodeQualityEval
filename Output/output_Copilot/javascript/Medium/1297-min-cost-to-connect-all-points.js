/**https://leetcode.com/problems/min-cost-to-connect-all-points/ */
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
// 
//Example 1:
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation: 
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
// 
//Constraints:
//	1 <= points.length <= 1000
//	-106 <= xi, yi <= 106
//	All pairs (xi, yi) are distinct.
/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
    const n = points.length;
    const edges = [];
    
    // Create all edges with their costs
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const cost = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
            edges.push([cost, i, j]);
        }
    }
    
    // Sort edges by cost
    edges.sort((a, b) => a[0] - b[0]);
    
    const parent = Array(n).fill(0).map((_, index) => index);
    
    function find(x) {
        if (parent[x] !== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    function union(x, y) {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
    
    let totalCost = 0;
    let edgesUsed = 0;
    
    for (const [cost, u, v] of edges) {
        if (union(u, v)) {
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed === n - 1) break; // All points are connected
        }
    }
    
    return totalCost;    
};