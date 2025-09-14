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
        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (const auto& edge : edges) {
            int cost = edge[0], x = edge[1], y = edge[2];
            if (find(parent, x) != find(parent, y)) {
                res += cost;
                unionSets(parent, x, y);
            }
        }
        return res;
    }
    
    int find(vector<int>& parent, int x) {
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }
    
    void unionSets(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }   
    }
};