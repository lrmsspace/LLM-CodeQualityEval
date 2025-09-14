/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//	For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
// 
//Example 1:
//Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
//Output: 2
//Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
//Example 2:
//Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
//Output: -1
// 
// 
//Constraints:
//	1 <= routes.length <= 500.
//	1 <= routes[i].length <= 105
//	All the values of routes[i] are unique.
//	sum(routes[i].length) <= 105
//	0 <= routes[i][j] < 106
//	0 <= source, target < 106
int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target) {
    int n = routesSize;
    int m = routesColSize[0];
    
    // Build adjacency list
    int** graph = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++) {
            graph[i][j] = routes[i][j];
        }
    }
    
    // Create a queue for breadth-first search
    int* queue = (int*)calloc(n * m, sizeof(int));
    int front = 0, rear = 0;
    
    // Mark the source bus as visited
    int* visited = (int*)calloc(n, sizeof(int));
    visited[source] = 1;
    
    // Create a map to store the bus stops and their corresponding buses
    int* busStops = (int*)calloc(n * m, sizeof(int));
    int* busToStop = (int*)calloc(n * m, sizeof(int));
    int busCount = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int stop = graph[i][j];
            if (stop == source) {
                busStops[busCount] = stop;
                busToStop[busCount++] = i;
            }
        }
    }
    
    // Perform breadth-first search
    queue[rear++] = source;
    while (front < rear) {
        int current = queue[front++];
        
        // Check if the current bus stop is the target
        if (current == target) {
            free(queue);
            free(visited);
            free(busStops);
            free(busToStop);
            for (int i = 0; i < n; i++) {
                free(graph[i]);
            }
            free(graph);
            return busCount;
        }
        
        // Find all buses that stop at the current bus stop
        for (int i = 0; i < busCount; i++) {
            int bus = busToStop[i];
            if (!visited[bus]) {
                visited[bus] = 1;
                
                // Add all adjacent bus stops to the queue
                for (int j = 0; j < m; j++) {
                    int adjacentStop = graph[bus][j];
                    if (adjacentStop!= -1) {
                        queue[rear++] = adjacentStop;
                    }
                }
            }
        }


        // Clear the visited flag for the current bus stop
        visited[current] = 0;
    }
    
    // Return -1 if no path is found
    free(queue);
    free(visited);
    free(busStops);
    free(busToStop);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return -1;
    
}