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
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    // Initialize a priority queue to store the points sorted by the manhattan distance
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < pointsSize; ++i) {
        pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
    }
    
    // Initialize a set to store the visited points
    unordered_set<pair<int, int>> visited;
    
    // Initialize the minimum cost
    int minCost = 0;
    
    // While there are still unvisited points
    while (pq.size() > 1 && visited.size() < pointsSize) {
        // Get the two points with the minimum cost
        int cost = pq.top().first;
        int x1 = pq.top().second.first;
        int y1 = pq.top().second.second;
        pq.pop();
        
        int x2 = pq.top().second.first;
        int y2 = pq.top().second.second;
        pq.pop();
        
        // If the points have not been visited before, add them to the set and update the minimum cost
        if (visited.find({x1, y1}) == visited.end() && visited.find({x2, y2}) == visited.end()) {
            minCost += cost;
            visited.insert({x1, y1});
            visited.insert({x2, y2});
            
            // Add the remaining points to the priority queue
            for (int i = 0; i < pointsSize; ++i) {
                if (visited.find({points[i][0], points[i][1]}) == visited.end()) {
                    pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
                }
            }
        }
    }
    
    // Return the minimum cost
    return minCost;
    
}