/**https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/ */
//There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.
//Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.
//In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).
//Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.
// 
//Example 1:
//Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: 11
//Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of passing fees.
//Example 2:
//Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: 48
//Explanation: The path to take is 0 -> 3 -> 4 -> 5, which takes 26 minutes and has $48 worth of passing fees.
//You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.
//Example 3:
//Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: -1
//Explanation: There is no way to reach city 5 from city 0 within 25 minutes.
// 
//Constraints:
//	1 <= maxTime <= 1000
//	n == passingFees.length
//	2 <= n <= 1000
//	n - 1 <= edges.length <= 1000
//	0 <= xi, yi <= n - 1
//	1 <= timei <= 1000
//	1 <= passingFees[j] <= 1000 
//	The graph may contain multiple edges between two nodes.
//	The graph does not contain self loops.
int minCost(int maxTime, int** edges, int edgesSize, int* edgesColSize, int* passingFees, int passingFeesSize) {
    int n = passingFeesSize;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < edgesSize; ++i) {
        int x = edges[i][0], y = edges[i][1], time = edges[i][2];
        graph[x].push_back({y, time});
        graph[y].push_back({x, time});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({passingFees[0], 0});
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if (dist[curr] < pq.top().first) continue;
        for (auto& [next, time] : graph[curr]) {
            int newDist = dist[curr] + time;
            if (newDist <= maxTime && newDist < dist[next]) {
                dist[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }
    return dist[n - 1] == INT_MAX? -1 : dist[n - 1];

}