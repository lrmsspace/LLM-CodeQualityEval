/**https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/ */
//There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
//There is a meeting for the representatives of each city. The meeting is in the capital city.
//There is a car in each city. You are given an integer seats that indicates the number of seats in each car.
//A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.
//Return the minimum number of liters of fuel to reach the capital city.
// 
//Example 1:
//Input: roads = [[0,1],[0,2],[0,3]], seats = 5
//Output: 3
//Explanation: 
//- Representative1 goes directly to the capital with 1 liter of fuel.
//- Representative2 goes directly to the capital with 1 liter of fuel.
//- Representative3 goes directly to the capital with 1 liter of fuel.
//It costs 3 liters of fuel at minimum. 
//It can be proven that 3 is the minimum number of liters of fuel needed.
//Example 2:
//Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
//Output: 7
//Explanation: 
//- Representative2 goes directly to city 3 with 1 liter of fuel.
//- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
//- Representative2 and representative3 go together to the capital with 1 liter of fuel.
//- Representative1 goes directly to the capital with 1 liter of fuel.
//- Representative5 goes directly to the capital with 1 liter of fuel.
//- Representative6 goes directly to city 4 with 1 liter of fuel.
//- Representative4 and representative6 go together to the capital with 1 liter of fuel.
//It costs 7 liters of fuel at minimum. 
//It can be proven that 7 is the minimum number of liters of fuel needed.
//Example 3:
//Input: roads = [], seats = 1
//Output: 0
//Explanation: No representatives need to travel to the capital city.
// 
//Constraints:
//	1 <= n <= 105
//	roads.length == n - 1
//	roads[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	roads represents a valid tree.
//	1 <= seats <= 105


    typedef struct {
        int city;
        int fuel;
    } Node;

    void dfs(int city, int parent, int seats, int* representatives, long long* fuelCost, Node** graph, int* graphSize) {
        representatives[city] = 1; // Each city has at least one representative
        for (int i = 0; i < graphSize[city]; i++) {
            int neighbor = graph[city][i].city;
            if (neighbor == parent) continue; // Skip the parent city
            dfs(neighbor, city, seats, representatives, fuelCost, graph, graphSize);
            representatives[city] += representatives[neighbor];
            *fuelCost += (representatives[neighbor] + seats - 1) / seats; // Calculate fuel cost
        }
    }

    long long minimumFuelCost(int** roads, int roadsSize, int* roadsColSize, int seats) {
        if (roadsSize == 0) return 0; // No roads, no fuel cost

        int n = roadsSize + 1; // Number of cities
        Node** graph = (Node**)malloc(n * sizeof(Node*));
        int* graphSize = (int*)calloc(n, sizeof(int));
        for (int i = 0; i < n; i++) {
            graph[i] = (Node*)malloc((n - 1) * sizeof(Node));
        }

        // Build the graph
        for (int i = 0; i < roadsSize; i++) {
            int a = roads[i][0], b = roads[i][1];
            graph[a][graphSize[a]++] = (Node){b, 0};
            graph[b][graphSize[b]++] = (Node){a, 0};
        }

        int* representatives = (int*)calloc(n, sizeof(int));
        long long fuelCost = 0;

        // Start DFS from the capital city (city 0)
        dfs(0, -1, seats, representatives, &fuelCost, graph, graphSize);

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(graph[i]);
        }
        free(graph);
        free(graphSize);
        free(representatives);

        return fuelCost;
    }
        

        