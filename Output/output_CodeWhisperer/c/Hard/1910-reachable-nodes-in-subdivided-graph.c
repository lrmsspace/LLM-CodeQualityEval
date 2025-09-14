/**https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/ */
//You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.
//The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.
//To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].
//In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.
//Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.
// 
//Example 1:
//Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
//Output: 13
//Explanation: The edge subdivisions are shown in the image above.
//The nodes that are reachable are highlighted in yellow.
//Example 2:
//Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
//Output: 23
//Example 3:
//Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
//Output: 1
//Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.
// 
//Constraints:
//	0 <= edges.length <= min(n * (n - 1) / 2, 104)
//	edges[i].length == 3
//	0 <= ui < vi < n
//	There are no multiple edges in the graph.
//	0 <= cnti <= 104
//	0 <= maxMoves <= 109
//	1 <= n <= 3000
int reachableNodes(int** edges, int edgesSize, int* edgesColSize, int maxMoves, int n) {
    // Create the graph
    Graph* graph = createGraph(n);
    
    // Add edges to the graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cnt = edges[i][2];
        
        // Add edges in both directions (undirected graph)
        addEdge(graph, u, v, cnt + 1);  // +1 because we need cnt+1 moves to go from u to v
        addEdge(graph, v, u, cnt + 1);
    }
    
    // Initialize distances array
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;  // Distance from source to itself is 0
    
    // Create min heap
    MinHeap* minHeap = createMinHeap(n);
    
    // Add all vertices to the min heap
    for (int i = 0; i < n; i++) {
        minHeap->array[i].node = i;
        minHeap->array[i].dist = dist[i];
        minHeap->size++;
    }
    
    // Process vertices using Dijkstra's algorithm
    while (!isEmpty(minHeap)) {
        HeapNode heapNode = extractMin(minHeap);
        int u = heapNode.node;
        
        // If distance is infinity, break
        if (dist[u] == INT_MAX)
            break;
        
        // Update distances of adjacent vertices
        for (int i = 0; i < graph->nodes[u].numEdges; i++) {
            int v = graph->nodes[u].edges[i].dest;
            int weight = graph->nodes[u].edges[i].weight;
            
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                decreaseKey(minHeap, v, dist[v]);
            }
        }
    }
    
    // Count reachable original nodes
    int reachableOriginal = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] <= maxMoves) {
            reachableOriginal++;
        }
    }
    
    // Count reachable subdivision nodes
    int reachableSubdivision = 0;
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cnt = edges[i][2];
        
        // Calculate how many subdivision nodes we can reach from both ends
        int fromU = max(0, maxMoves - dist[u]);
        int fromV = max(0, maxMoves - dist[v]);
        
        // The total reachable is the minimum of the total nodes and the sum of what we can reach from both ends
        reachableSubdivision += min(cnt, fromU + fromV);
    }
    
    // Clean up
    free(dist);
    free(minHeap->array);
    free(minHeap);
    for (int i = 0; i < n; i++) {
        if (graph->nodes[i].edges) {
            free(graph->nodes[i].edges);
        }
    }
    free(graph->nodes);
    free(graph);
    
    // Return total reachable nodes
    return reachableOriginal + reachableSubdivision;
}   