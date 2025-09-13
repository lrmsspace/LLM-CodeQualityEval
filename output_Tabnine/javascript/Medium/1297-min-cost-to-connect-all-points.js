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
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            edges.push([points[i][0] - points[j][0], points[i][1] - points[j][1], i, j]);
        }
    }
    edges.sort((a, b) => a[0] ** 2 + a[1] ** 2 - (b[0] ** 2 + b[1] ** 2));
    
    const parent = Array(n).fill(null).map((_, i) => i);
    const rank = Array(n).fill(0);
    
    function find(x) {
        if (parent[x] === x) return x;
        return parent[x] = find(parent[x]);
    }
    
    let res = 0;
    for (let [cost, _, u, v] of edges) {
        const rootU = find(u);
        const rootV = find(v);
        if (rootU!== rootV) {
            if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            res += cost;
        }
    }
    return res;
    
};