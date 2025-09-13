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
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        
        // Initialize the distance from the first point to all other points
        for (int i = 1; i < n; ++i) {
            dist[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
        }
        
        // Perform Kruskal's algorithm
        int minCost = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u = find(parent, 0);
            int v = find(parent, min_element(dist.begin() + 1, dist.end()) - dist.begin());
            
            if (u!= v) {
                minCost += dist[v];
                unionSet(parent, u, v);
            }
            
            // Update the distance to the next point
            for (int j = 1; j < n; ++j) {
                if (!visited[j]) {
                    dist[j] = min(dist[j], abs(points[u][0] - points[j][0]) + abs(points[u][1] - points[j][1]));
                }
            }
        }
        
        return minCost;
        
    }
};