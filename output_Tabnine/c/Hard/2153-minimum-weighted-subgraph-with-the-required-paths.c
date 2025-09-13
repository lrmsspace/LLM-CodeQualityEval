/**https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/ */
//You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.
//You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.
//Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.
//Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.
//A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.
// 
//Example 1:
//Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
//Output: 9
//Explanation:
//The above figure represents the input graph.
//The blue edges represent one of the subgraphs that yield the optimal answer.
//Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.
//Example 2:
//Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
//Output: -1
//Explanation:
//The above figure represents the input graph.
//It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.
// 
//Constraints:
//	3 <= n <= 105
//	0 <= edges.length <= 105
//	edges[i].length == 3
//	0 <= fromi, toi, src1, src2, dest <= n - 1
//	fromi != toi
//	src1, src2, and dest are pairwise distinct.
//	1 <= weight[i] <= 105
long long minimumWeight(int n, int** edges, int edgesSize, int* edgesColSize, int src1, int src2, int dest) {

    // Implement the algorithm to find the minimum weighted subgraph satisfying the given constraints
    //...
    // Your code here...
    // Construct the adjacency list representation of the graph
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        adjList[from].push_back({to, weight});
    }
    
    // Implement Dijkstra's algorithm to find the shortest path from src1 to dest
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src1});
    vector<int> dist(n, INT_MAX);
    dist[src1] = 0;
    
    while (!pq.empty()) {
        int currNode = pq.top().second;
        pq.pop();
        
        for (auto& edge : adjList[currNode]) {
            int neighbor = edge.first;
            int weight = edge.second;
            
            if (dist[neighbor] > dist[currNode] + weight) {
                dist[neighbor] = dist[currNode] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    // Check if a path exists from src2 to dest
    if (dist[dest] == INT_MAX) {
        return -1;
    }
    
    // Construct the adjacency list representation of the subgraph
    vector<vector<pair<int, int>>> subgraphAdjList(n);
    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        
        if (dist[from] + weight <= dist[dest] && dist[to] + weight <= dist[dest]) {
            subgraphAdjList[from].push_back({to, weight});
            subgraphAdjList[to].push_back({from, weight});
        }
    }
    
    // Implement Prim's algorithm to find the minimum spanning tree of the subgraph
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> weight(n, INT_MAX);
    weight[src1] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minWeight = INT_MAX;
        int minNode = -1;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && weight[j] < minWeight) {
                minWeight = weight[j];
                minNode = j;
            }
        }
        
        visited[minNode] = true;
        
        for (auto& edge : subgraphAdjList[minNode]) {
            int neighbor = edge.first;
            int edgeWeight = edge.second;
            
            if (!visited[neighbor] && edgeWeight < weight[neighbor]) {
                weight[neighbor] = edgeWeight;
                parent[neighbor] = minNode;
            }
        }
    }
    
    // Calculate the total weight of the subgraph
    long long totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i]!= -1) {
            totalWeight += weight[i];
        }
    }
    
    return totalWeight;
    
}