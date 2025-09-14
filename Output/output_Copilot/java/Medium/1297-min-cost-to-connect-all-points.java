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
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[] parent = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
                edges.add(new int[]{i, j, cost});
            }
        }
        Collections.sort(edges, (a, b) -> a[2] - b[2]);
        int res = 0;
        for (int[] edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if (x != y) {
                if (rank[x] > rank[y]) {
                    parent[y] = x;
                } else if (rank[x] < rank[y]) {
                    parent[x] = y;
                } else {
                    parent[y] = x;
                    rank[x]++;
                }
                res += edge[2];
            }
        }
        return res;        
    }
}